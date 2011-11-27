#!/bin/sh

pwd="$(pwd)"
dir="$(dirname "$0")"

cd "$dir"
autoreconf -vfi || exit 1

cd "$pwd"
exec "$dir/configure" "$@"
