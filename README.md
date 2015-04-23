# Back
Another build system, similar to [Tup](http://gittup.org/tup/).

## Premise
Back is a DAG-driven build system that relies on reverse dependency "pushing"
(backwards to GNU Make) to schedule tasks.

It is designed around one central concept: simplicity. The core components of
Back are a key store database, some basic architecture-specific wrappers, a
small binding to Lua, topped with a light abstraction layer.

Back is a platform.

## Goals
Back is intended to be an eventual drop-in replacement for Make, as well as a
complete redesign of [Tup](http://gittup.org/tup). It also aims to provide a
means to easily manage dependency acquisition.

## Design
Back is module-centric; that is, pieces of the project are black-boxed together
into components that expose inputs and outputs.

When configuring Back, you map these inputs and outputs together to form
build chains. When invoking Back, you may designate specific inputs or reroute
outputs.

# Building
Building is done through a bootstrap script and the use of `tup`.

## Prerequisites
There are a few tools needed in order to bootstrap successfully:

- **Ubuntu**: `sudo apt-get install libtool autogen`

As well, make sure `/usr/bin/sed` points to a binary of `sed` - not sure why
Snappy (the most problematic library in Back) requires this.

You will also need [Tup](http://gittup.org/tup).

## Building
Simply bootstrap and build:

1. `./boostrap -f`
2. `tup init && tup`

If all goes as planned, `back` should be smugly sitting in your project root.

# License
Back is licensed under the MIT License.

Go nuts.
