"""
Copies a file from vospace to the local machine then opens it in ds9.
"""

import sys

from astropy.io import fits
import ds9
import vos

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print "Usage: python %s <vospace uri>" % sys.argv[0]
        sys.exit(1)

    remote_file = sys.argv[1]

    # Load data from vospace by first copying to a local file
    local_file = "/tmp/%s" % remote_file.split("/")[-1]
    client = vos.Client()
    client.copy(remote_file, local_file)
    data = fits.open(local_file)

    # Open in ds9
    d = ds9.ds9()
    d.set_pyfits(data)
    d.set("zoom to fit")