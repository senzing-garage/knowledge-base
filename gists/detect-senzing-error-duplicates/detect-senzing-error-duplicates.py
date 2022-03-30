#! /usr/bin/env python3

# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------

if __name__ == "__main__":

    input_file_name = "errorids.h"
    keyword = "EASErrorMessage"
    message_list = []

    with open(input_file_name) as input_file:
        for line in input_file:
            index_of_keyword = line.find(keyword)
            if index_of_keyword >= 0:
                index_of_comma = line.find(',', index_of_keyword)
                error_code = line[index_of_keyword + len(keyword) + 1:index_of_comma]
                if error_code in message_list:
                    print("Duplicate: {0}".format(error_code))
                else:
                    message_list.append(error_code)
