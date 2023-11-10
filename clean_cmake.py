import os, shutil

def clean_folder(current_folder: str):
    try:
        shutil.rmtree(os.path.join(current_folder, 'CMakeFiles'))
    except:
        pass
    for folder in os.listdir(current_folder):
        if os.path.isdir(os.path.join(current_folder, folder)):
            clean_folder(os.path.join(current_folder, folder))

home_folder = os.path.dirname(os.path.abspath(__file__))
clean_folder(home_folder)