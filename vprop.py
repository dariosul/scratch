#!/usr/bin/env python
"""
Convenience commands for getting/setting properties of nodes in VOSpace.
"""

__author__ = "David Rusk <drusk@uvic.ca>"

import argparse
import sys

import vos


OSSOS_TAG_URI_BASE = "ivo://canfar.uvic.ca/ossos"


class VOSpacePropertyAccessor(object):
    def __init__(self):
        self.vosclient = vos.Client()

    def get_property(self, args):
        node = self.get_node(args.node_uri)

        property_uri = self.get_property_uri(args.key)

        if property_uri not in node.props:
            sys.stdout.write("%s is not a property of %s\n" %
                             (property_uri, args.node_uri))
            return

        sys.stdout.write("%s\n" % node.props[property_uri])

    def set_property(self, args):
        node = self.get_node(args.node_uri)
        node.props[self.get_property_uri(args.key)] = args.value
        self.vosclient.addProps(node)

    def get_node(self, uri):
        return self.vosclient.getNode(uri)

    def get_property_uri(self, property_name):
        return OSSOS_TAG_URI_BASE + "#" + property_name


if __name__ == "__main__":
    vospace_accessor = VOSpacePropertyAccessor()

    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers()

    get_parser = subparsers.add_parser("get")
    get_parser.add_argument("node_uri")
    get_parser.add_argument("key")
    get_parser.set_defaults(func=vospace_accessor.get_property)

    set_parser = subparsers.add_parser("set")
    set_parser.add_argument("node_uri")
    set_parser.add_argument("key")
    set_parser.add_argument("value")
    set_parser.set_defaults(func=vospace_accessor.set_property)

    args = parser.parse_args()
    args.func(args)
