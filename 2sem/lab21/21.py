from os import walk 
from os.path import join 

def count_lines(filename): 
    with open(filename, 'r') as f:
        return sum(1 for _ in f)
        
def count_lines_in_dir(dir_path): 
    total_lines = 0 
    for dirpath, dirnames, filenames in walk(dir_path):
        for filename in filenames:
            if filename.endswith(('.h', '.cpp')):
                file_path = join(dirpath, filename)
                total_lines += count_lines(file_path)
    return total_lines
 
dir_path = input('Enter the directory or put ?: ') 
if dir_path=='?' :
    dir_path='/home/ann/Загрузки/bashpy'

total_lines = count_lines_in_dir(dir_path)

print(total_lines)
