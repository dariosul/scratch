# Copyright (C) 2013 David Rusk
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.

__author__ = "David Rusk <drusk@uvic.ca>"

from datetime import datetime
import time

import feedparser
import pymongo


def parse_postings(feed_data):
    # TODO: clean out markup?
    postings = feed_data["entries"]

    # TODO: find out what this field is for and why it is a time_struct
    for posting in postings:
        posting["published_parsed"] = convert_time_struct_to_datetime(
            posting["published_parsed"])

    return postings


def convert_time_struct_to_datetime(time_struct):
    """MongoDB requires datetime objects."""
    return datetime.fromtimestamp(time.mktime(time_struct))


def write_to_db(job_postings):
    client = pymongo.MongoClient()

    db = client.job_postings
    db.viatec_jobs.insert(job_postings)


def main():
    feed_data = feedparser.parse("http://www.viatec.ca/job-board/feed")
    job_postings = parse_postings(feed_data)
    write_to_db(job_postings)


if __name__ == "__main__":
    main()
