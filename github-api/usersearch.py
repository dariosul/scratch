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

import requests

GH_API_URL_BASE = "https://api.github.com/"
GH_API_HEADERS = {"Accept": "application/vnd.github.preview"}


def search_users(params):
    response = requests.get(GH_API_URL_BASE + "search/users", params=params,
                            headers=GH_API_HEADERS)
    return response.json()


def query_user(username):
    response = requests.get(GH_API_URL_BASE + "users/{}".format(username))
    return response.json()


def get_repository_languages(username):
    response = requests.get(GH_API_URL_BASE + "users/{}/repos".format(username))
    return [repo["language"] for repo in response.json()]


if __name__ == "__main__":
    user_data = search_users({"q": "location:victoria"})

    usernames = [user["login"] for user in user_data["items"]]

    print "Got {} usernames".format(len(usernames))

    username = usernames[0]
    print username

    # print query_user(username)

    languages = set(get_repository_languages(username))
    print "Repository languages ({})".format(len(languages))
    print languages
