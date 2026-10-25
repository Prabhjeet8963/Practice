import qrcode
website_link = 'https://youtube.com/shorts/adIsLG-aCEA?si=Y0OEasjUe2lmiUCI'
qr=qrcode.QRCode(version=1,box_size=5,border = 5)

'''The version parameter is an integer from 1 to 40 that controls the size of the QR code.
The box_size parameter controls how many pixels each “box” of the QR code is.
The border parameter controls how many boxes thick the border should be.'''

qr.add_data(website_link)
qr.make()
img = qr.make_image(fill_color = 'black', back_color = 'white')
img.save('youtube_qr.png')
# we have to store and save the file
