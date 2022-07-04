import time
with open("../filesToSort/smallSort.MKTI",'rb') as f:
    contents = f.read()
    input("loaded")
    a = time.process_time()
    print(sorted(contents))
    print(time.process_time()-a)