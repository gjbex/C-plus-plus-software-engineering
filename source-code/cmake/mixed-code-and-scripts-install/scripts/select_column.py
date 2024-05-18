#!/usr/bin/env python

import argparse
import csv
import sys
from utils import csv_utils

if __name__ == '__main__':
    arg_parser = argparse.ArgumentParser(description='select a column of a CSV file')
    arg_parser.add_argument('--col', type=int, required=True,
                            help='number of the column to select (1-based)')
    arg_parser.add_argument('file_name', help='CSV file to process')
    arg_parser.add_argument('--sniff', type=int, default=1024,
                            help='number of bytes to use to determine CSV dialect')
    options = arg_parser.parse_args()

    try:
        with open(options.file_name, 'r') as csv_file:
            csv_reader = csv_utils.create_reader(csv_file, options.sniff)
            for row in csv_reader:
                print(row[options.col - 1])
    except FileNotFoundError as error:
        print(f'error: invalid file name "{options.file_name}"', file=sys.stderr)
        sys.exit(csv_utils.INVALID_FILE_NAME_STATUS)
    except IndexError as error:
        print(f'error: invalid column number {options.col}', file=sys.stderr)
        sys.exit(csv_utils.INVALID_COLUMN_NUMBER_STATUS)
