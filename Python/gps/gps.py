import subprocess
import json
import time
from datetime import datetime

def get_gps_location():
    # Call termux-location command
    result = subprocess.run(['termux-location'], capture_output=True, text=True)
    if result.returncode == 0:
        # Parse the JSON output
        location_data = json.loads(result.stdout)
        # Extract relevant information
        latitude = location_data['latitude']
        longitude = location_data['longitude']
        altitude = location_data['altitude']
        accuracy = location_data['accuracy']
        return latitude, longitude, altitude, accuracy
    else:
        print("Error getting location:", result.stderr)
        return None, None, None

if __name__ == "__main__":
    now = datetime.now()
    now_format = now.strftime("%Y/%m/%d %H:%M:%S")
    print(f"Date    : {now_format}")                        
    #print("Fetching GPS location...")
    # The first call might take a moment to warm up the GPS sensor
    lat, lon, alt, acc = get_gps_location()
    if lat is not None:                                         
        print(f"Latitude: {lat}")
        print(f"Longitude: {lon}")                              
        print(f"Altitude: {alt}")
        print(f"Accuracy: {acc} meters")
        print(f"----")
    else:
        print("Failed to retrieve GPS location.")
