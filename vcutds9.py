"""
Open a cutout of a vospace file in ds9.
Nothing gets written to disk, it is all in memory.
"""

import argparse
import cStringIO

from astropy.io import fits
import ds9
import vos

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Open a cutout of a vospace file in ds9.")
    parser.add_argument("remote_file", type=str, help="The vospace file to open")
    parser.add_argument("cutout", type=str, help="The cutout to perform")
    args = parser.parse_args()

    client = vos.Client()
    vofile = client.open(args.remote_file, view="cutout", cutout=args.cutout)

    rawdata = cStringIO.StringIO(vofile.read())
    hdulist = fits.open(rawdata)

    # Open in ds9
    d = ds9.ds9()
    d.set_pyfits(hdulist)
