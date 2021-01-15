import sys

args = sys.argv

if args[1] == 'test':
    try:
        import os
        path = os.getcwd()
        os.chdir(path + "/functions")
        os.system("cp functions.c functions.h ../test/")
        os.chdir(path + "/test")
        os.system("make")
        print("Compilation done!\n")
        os.system("./test")
        print("Unit-Test done!\n")
    except ModuleNotFoundError:
        print("Module os not found")
    except OSError:
        print("Problem with your path")
    except ValueError:
        print("Error can't get the current path")
    except:
        print("Unexpected error:", sys.exc_info()[0])
    else:
        os.system("rm functions.c functions.h && make clean")
        os.chdir(path)
        print("DONE!")

elif args[1] == 'main':
    try:
        import os
        path = os.getcwd()
        os.chdir(path + "/functions")
        os.system("cp functions.c functions.h ../.")
        os.chdir(path)
        os.system("make")
        print("Compilation done!\n")
        os.system("./main")
        print("Your tests are done!\n")
    except ModuleNotFoundError:
        print("Module os not found")
    except OSError:
        print("Problem with your path")
    except ValueError:
        print("Error can't get the current path")
    except:
        print("Unexpected error:", sys.exc_info()[0])
    else:
        os.system("rm functions.c functions.h && make clean")
        print("DONE!")



