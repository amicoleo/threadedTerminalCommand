Openframeworks example project for using system calls in a threaded process. Useful if for instance you want to use python instead of c++ for networking. The script is executed in a different thread, so it doesn't block drawing functions etc...

The project is just for OSX systems and has been tested on OF09.

# Notes
- This example uses Microsoft Emotion API - it's free if you don't need too many calls, but you'll need to register and obtain the Subscription Key, which than needs to be placed in the imageEmotion.py script in microsoftEmotionSubscriptionKey

- If using project generator, you need to restore the xcode buld script as the project generator resets it to default.

  On projectName > build phases > run script add
  ```
  rsync -aved *.py "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/"

  ```

- The example uses ofxJSON. Which takes away the pain to parse json response strings.
