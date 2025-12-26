import os

import json

import csv

import requests

from datetime import datetime

def fetch_cve_change_histories(start_date, end_date):
    jls_extract_var = "https://services.nvd.nist.gov/rest/json/cvehistory/2.0"
    url = jls_extract_var
    params = {

        "startDate": start_date,

        "endDate": end_date,

        "resultsPerPage": 5000

    }

    response = requests.get(url, params=params)

    response.raise_for_status()

    return response.json()


def save_json_file(data, filename):

    with open(filename, "w") as json_file:

        json.dump(data, json_file, indent=4)

def save_to_csv(data, filename):

    with open(filename, mode="w", newline="", encoding="utf-8") as csv_file:

        writer = csv.writer(csv_file)

        header = ["CVE ID", "Event Name", "CVE Change ID", "Source Identifier", "Created Date", "Action", "Type", "New Value"]

        writer.writerow(header)


        for change in data.get("cveChanges", []):

            row = [

                change["change"].get("cveId"),

                change["change"].get("eventName"),

                change["change"].get("cveChangeId"),

                change["change"].get("sourceIdentifier"),

                change["change"].get("created")

            ]

            for detail in change["change"].get("details", []):

                writer.writerow(row + [detail.get("action"), detail.get("type"), detail.get("newValue")])


def display_text(data, filter_key):

    print(f"\nCVE Changes - {filter_key}\n")

    for change in data.get("cveChanges", []):

        details = change["change"].get("details", [])

        if filter_key == "Added" or filter_key == "Changed":
            for detail in details:

                if detail.get("action") == filter_key:

                    print(json.dumps(change, indent=4), "\n")
        else:

            summary = {

                "cveId": change["change"].get("cveId"),

                "eventName": change["change"].get("eventName"),

                "sourceIdentifier": change["change"].get("sourceIdentifier"),

                "created": change["change"].get("created")

            }

            print(json.dumps(summary, indent=4), "\n")

def validate_dates(start_date, end_date):

    try:

        start = datetime.strptime(start_date, "%Y-%m-%d")

        end = datetime.strptime(end_date, "%Y-%m-%d")

        if start > end:

            print("Error: End date cannot be earlier than start date. Please try again.")

            return False

        return True

    except ValueError:

        print("Error: Invalid date format. Please use YYYY-MM-DD.")

        return False

def main():

    if os.path.exists("cveCH_raw.json"):

        load_file = input("Found 'cveCH_raw.json'. Do you want to load it? (yes/no): ").strip().lower() == "yes"
        if load_file:

            with open("cveCH_raw.json", "r") as file:

                data = json.load(file)
        else:

            while True:

                start_date = input("Enter start date (YYYY-MM-DD): ")

                end_date = input("Enter end date (YYYY-MM-DD): ")
                if validate_dates(start_date, end_date):

                    break

            data = fetch_cve_change_histories(start_date, end_date)

            save_json_file(data, "cveCH_raw.json")
    else:

        while True:

            start_date = input("Enter start date (YYYY-MM-DD): ")

            end_date = input("Enter end date (YYYY-MM-DD): ")
            if validate_dates(start_date, end_date):

                break

        data = fetch_cve_change_histories(start_date, end_date)

        save_json_file(data, "cveCH_raw.json")


    save_to_csv(data, "cveCH_parsed.csv")


    for key in ["Added", "Changed", "Summary"]:

        display_text(data, key)


if __name__ == "__main__":
    main()

