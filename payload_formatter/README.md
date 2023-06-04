# TTN Payload Formatter

This directory contains a JavaScript file with a function called **decodeUplink()**. This function is used as a payload formatter in The Things Network (TTN).

The payload formatter is used to convert the raw payload data sent by the devices into a structured JSON object.

## Using the payload formatter

To use the payload formatter, follow these steps:
- Log in to your TTN account and navigate to the application that your device is registered to.
- Click on the "Payload formatters" tab.
- In the "Uplink" section, select "Custom" from the formatter type dropdown menu.
- Copy the **decodeUplink()** function from the [decodeUplink.js](./decodeUplink.js) file and paste it into the text box.
- Click "Save" to update the payload formatter.

Note: Ensure that your device is transmitting data in the format expected by the decodeUplink() function.

