import csv


INVALID_COLUMN_NUMBER_STATUS = 1
INVALID_FILE_NAME_STATUS = 2

def create_reader(file, nr_byles=1024):
    dialect = csv.Sniffer().sniff(file.read(nr_byles))
    file.seek(0)
    return csv.reader(file, dialect=dialect)
