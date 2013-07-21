#!/usr/bin/env python
"""
Download a cutout of a VOSpace file and write it in the current directory.

Example:
python vdlcut.py vos://cadc.nrc.ca~vospace/OSSOS/dbimages/1616681/1616681p.fits [23]
"""

__author__ = "David Rusk <drusk@uvic.ca>"

import argparse
import sys

import vos

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Download a cutout of a vospace file.")
    parser.add_argument("remote_file", type=str, help="The vospace file to open")
    parser.add_argument("cutout", type=str, help="The cutout to perform")
    args = parser.parse_args()

    client = vos.Client()
    vofile = client.open(args.remote_file, view="cutout", cutout=args.cutout)

    download_filename = "cutout-" + args.remote_file.split("/")[-1]
    with open(download_filename, "wb") as filehandle:
        filehandle.write(vofile.read())

    sys.stdout.write("Download of cutout complete: %s\n" % download_filename)
