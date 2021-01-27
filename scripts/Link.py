import sys
import os

os.chdir("..\\src")
Content = os.listdir()

Empty = ""
Files = []
for Filenames in Content:
    if Filenames.endswith(".cpp") and not Filenames.startswith("Glass.cpp"):
        Files.append(Filenames)

for Iterations in Files:
    Empty += f" {Iterations}"

os.system(f"g++ Glass.cpp {Empty}");
sys.exit()
