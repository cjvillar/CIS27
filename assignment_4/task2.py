import io
from numpy import random

def randNum():
    # gen random int from 1 - 1000, 1000 times
    array = [random.randint(1000) for _ in range(1000)]
    return array

def save_array(random_array):
    # create in-memory buffer
    buffer = io.StringIO()
    
    # write to the buffer
    for n in random_array:
        buffer.write(str(n) + ", ")

    # write entire buffer to the file 
    with open("randPythonArray.txt", "w") as f:
        f.write(buffer.getvalue())

    # close buffer
    buffer.close()


#add funct to read from file and go to stdout

if __name__ == "__main__":
    random_array = randNum()
    print(random_array)  # print to console
    save_array(random_array)  # save to file

