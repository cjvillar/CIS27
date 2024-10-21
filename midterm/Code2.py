import io #lib to work with input strings

# create global buffer
buffer = io.StringIO()

# set the file
infile = "ilovetocode.txt"


def read_from_file():
    "Read contents of infile into buffer"
    with open(infile, "r") as file:
        buffer.write(file.read())

    buffer.seek(0)  # sets buffer back to first index
    data = buffer.read()  # read data from buffer
    print(data)


def count_chars():
    """Count how many characters in the input file"""
    char_count = 0
    buffer.seek(0)
    for string in buffer:
        for char in string:
                char_count += 1

    print(f"{infile} has {char_count} characters")


def count_upper():
    """Count how many uppercase characters in the input file"""
    upper_count = 0
    buffer.seek(0)
    for string in buffer:
        for char in string:
            if "A" <= char <= "Z":
                upper_count += 1
    print(f"{infile} has {upper_count} UPPERCASE characters")


def count_lower():
    """Count how many lowercase characters in the input file"""
    lower_count = 0
    buffer.seek(0)
    for string in buffer:
        for char in string:
            if "a" <= char <= "z":
                lower_count += 1
    print(f"{infile} has {lower_count} LOWERCASE characters")


if __name__ == "__main__":
    read_from_file()  # output file from buffer
    count_chars()
    #count_upper()
    #count_lower()
