__author__ = "David Rusk <drusk@uvic.ca>"

import ctypes

libhello = ctypes.cdll.LoadLibrary("./libhello.so")


def main():
    libhello.hello()


if __name__ == "__main__":
    main()
