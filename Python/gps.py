
import android
import time

droid = android.Android()
droid.makeToast("Fetching GPS data")
print("Starting GPS sensor...")
droid.startLocating()

# Wait for a location event
event = droid.eventWaitFor('location', 10000).result

if event['name'] == "location":
    try:
        # Try to get GPS data
        data = event['data']['gps']
        latitude = data['latitude']
        longitude = data['longitude']
        altitude = data['altitude']
        print(f"Latitude: {latitude}, Longitude: {longitude}, Altitude: {altitude}")
    except KeyError:
        print("No GPS data available, checking network location...")
        # Handle network location data if GPS is unavailable
        pass

droid.stopLocating()


