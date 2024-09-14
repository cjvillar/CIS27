import sys

data = 10.0
print(sys.getsizeof(data))
data = 100000.5
print(sys.getsizeof(data))
data = 100000000.5
print(sys.getsizeof(data))