#!/bin/bash

exec socat - TCP4:localhost:$(<port)
