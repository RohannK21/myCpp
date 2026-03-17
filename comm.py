import os
import subprocess
import random
from datetime import datetime, timedelta

# --- CONFIGURATION ---
SOLUTIONS_DIR = "LeetCode_solns" 
START_DATE = datetime(2026, 2, 2)
END_DATE = datetime(2026, 3, 10)

def get_random_date(start, end):
    delta = end - start
    random_days = random.randrange(delta.days)
    random_seconds = random.randrange(86400)
    return start + timedelta(days=random_days, seconds=random_seconds)

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    os.chdir(script_dir)

    if not os.path.exists(SOLUTIONS_DIR):
        print(f"Error: Could not find '{SOLUTIONS_DIR}'")
        return

    # Get all files
    files = [f for f in os.listdir(SOLUTIONS_DIR) if os.path.isfile(os.path.join(SOLUTIONS_DIR, f))]
    
    print(f"Starting batch commit for {len(files)} files...")

    for filename in files:
        # Use forward slashes for Git path consistency
        file_path = f"{SOLUTIONS_DIR}/{filename}"
        
        # Check if already committed
        check = subprocess.run(f'git ls-files "{file_path}"', shell=True, capture_output=True, text=True)
        if check.stdout.strip():
            print(f"Skipping {filename} (Already in Git)")
            continue

        commit_date = get_random_date(START_DATE, END_DATE)
        formatted_date = commit_date.strftime('%Y-%m-%dT%H:%M:%S')

        # 1. Add
        subprocess.run(f'git add "{file_path}"', shell=True)
        
        # 2. Commit with Backdate
        cmd = (
            f'set GIT_AUTHOR_DATE={formatted_date}&& '
            f'set GIT_COMMITTER_DATE={formatted_date}&& '
            f'git commit -m "Add solution: {filename}"'
        )

        result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
        
        if result.returncode == 0:
            print(f"✅ Committed: {filename} -> {formatted_date}")
        else:
            print(f"❌ Failed: {filename} -> {result.stderr}")

    print("\n--- BATCH COMPLETE ---")
    print("Now run: git push origin main")

if __name__ == "__main__":
    main()