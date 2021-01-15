import sys

if not sys.platform == "linux":
    raise SystemError("Not the good os.")
args = sys.argv
if len(args) != 2:
    raise NotImplementedError("Please put at least one arg (main or test)")

if args[1] == 'test':
    try:
        import os
        path = os.getcwd()
        os.chdir(path + "/functions")
        os.system("cp functions.c functions.h ../test/")
        os.chdir(path + "/test")
        os.system("make")
        print("Compilation done!\n")
        os.system("echo '------TESTS------' | lolcat")
        print()
        os.system("./test")
        print()
        os.system("echo '------DONE!------' | lolcat")
        print()
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
        print("Directory cleaned.")

elif args[1] == 'main':
    try:
        import os
        path = os.getcwd()
        os.chdir(path + "/functions")
        os.system("cp functions.c functions.h ../.")
        os.chdir(path)
        os.system("make")
        print("Compilation done!\n")
        os.system("echo '------TESTS------' | lolcat")
        print()
        os.system("./main | lolcat")
        print()
        os.system("echo '------DONE!------' | lolcat")
        print()
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
        print("Directory cleaned.")

else:
    raise NotImplementedError("Bad args, please put at least one arg (main or test)")


