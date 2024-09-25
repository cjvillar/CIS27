import io
from numpy import random

# create in-memory buffer
buffer = []

def randNum():
    # generate random integers from 1 - 1000, 1000 times
    array = [random.randint(1000) for _ in range(1000)]
    return array


def save_array(random_array, buffer):
    # fill buffer with array data
    buffer[:] = random_array

    # write entire buffer to the file
    with open("randPythonArray.txt", "w") as f:
        for num in buffer:
            f.write(f"{num}\n")


# function to read from file and print to stdout
def read_array(buffer):
    buffer.clear()  # clear the buffer before reading

    with open("randPythonArray.txt", "r") as f:
        for line in f:
            buffer.append(int(line.strip()))  # convert each line back to an integer
    print(buffer)


if __name__ == "__main__":
    random_array = randNum()
    save_array(random_array, buffer)  # save to file
    read_array(buffer)  # read from file and print
