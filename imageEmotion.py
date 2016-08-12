import httplib, urllib, base64, sys

microsoftEmotionSubscriptionKey = 'XXX'

with open(sys.argv[1], 'rb') as f:
    data = f.read()

    headers = {
        'Content-Type': 'application/octet-stream',
        'Ocp-Apim-Subscription-Key': microsoftEmotionSubscriptionKey,
    }

    try:
        conn = httplib.HTTPSConnection('api.projectoxford.ai')
        conn.request("POST", "/emotion/v1.0/recognize", data, headers)
        response = conn.getresponse()
        data = response.read()
        print(data)
        conn.close()
    except Exception as e:
        print(e.strerror)
