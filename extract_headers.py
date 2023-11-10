import os, shutil

home_folder = os.path.dirname(os.path.abspath(__file__))
headers_folder = os.path.join(home_folder, 'headers')

def extract_folder(current_folder: str):
    if current_folder.split('/')[-1] in ['headers', 'gtest', 'eigen', 'tests', 'benchmark']:
        return

    for current_file in os.listdir(current_folder):
        if os.path.isdir(os.path.join(current_folder, current_file)):
            extract_folder(os.path.join(current_folder, current_file))
        elif current_file.endswith('.h'):
            shutil.copy(os.path.join(current_folder, current_file), os.path.join(headers_folder, current_file))

if os.path.exists(headers_folder):
    shutil.rmtree(headers_folder)
os.mkdir(headers_folder)
extract_folder(home_folder)