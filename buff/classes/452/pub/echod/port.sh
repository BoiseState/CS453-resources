#!/bin/bash

echo $(((UID&0x7fff)+234)) | tee port

