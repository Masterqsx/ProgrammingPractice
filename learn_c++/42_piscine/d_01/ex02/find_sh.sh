#!/bin/sh
  find . -name "*.sh"|awk -F "/" '{print $NF}'|sed "s/.sh$//"
