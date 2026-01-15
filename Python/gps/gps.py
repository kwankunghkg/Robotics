import subprocess
import json
import time

def get_gps_location():
    # Call termux-location command
    result = subprocess.run(['termux-location'], capture_output=True, text=True)
    if result.returncode == 0:
        # Parse the JSON output
        location_data = json.loads(result.stdout)
        # Extract relevant information
        latitude = location_data['latitude']
        longitude = location_data['longitude']
        accuracy = location_data['accuracy']
        return latitude, longitude, accuracy
    else:
        print("Error getting location:", result.stderr)
        return None, None, None

if __name__ == "__main__":
    print("Fetching GPS location...")
    # The first call might take a moment to warm up the GPS sensor
    lat, lon, acc = get_gps_location()
    if lat is not None:
        print(f"Latitude: {lat}")
        print(f"Longitude: {lon}")
        print(f"Accuracy: {acc} meters")
    else:
        print("Failed to retrieve GPS location.")

