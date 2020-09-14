#ifndef FIREBASE_HTTP_CLIENT_H
#define FIREBASE_HTTP_CLIENT_H

#include "Arduino.h"
#include "Stream.h"

struct HttpStatus {
  static const int TEMPORARY_REDIRECT = 307;
};

class FirebaseHttpClient {
 public:
  static FirebaseHttpClient* create();

  virtual void setReuseConnection(bool reuse) = 0;
  virtual void begin(const String& url) = 0;
  virtual void begin(const String& host, const String& path) = 0;

  virtual void end() = 0;

  virtual void addHeader(const String& name, const String& value) = 0;
  virtual void collectHeaders(const char* header_keys[],
                              const int header_key_count) = 0;
  virtual String header(const String& name) = 0;

  virtual int sendRequest(const String& method, const String& data) = 0;

  virtual String getString() = 0;

  virtual Stream* getStreamPtr() = 0;

  virtual String errorToString(int error_code) = 0;

 protected:
  static const uint16_t kFirebasePort = 443;
};

static const String kFirebaseFingerprint =
      // "7A 54 06 9B DC 7A 25 B3 86 8D 66 53 48 2C 0B 96 42 C7 B3 0A";
      // "9A E1 A3 B7 88 E0 C9 A3 3F 13 72 4E B5 CB C7 27 41 B2 0F 6A";   //Dec 15, 2016
      // "B8 4F 40 70 0C 63 90 E0 07 E8 7D BD B4 11 D0 4A EA 9C 90 F6";   //2017-8-18 4:34:24
      // "6F D0 9A 52 C0 E9 E4 CD A0 D3 02 A4 B7 A1 92 38 2D CA 2F 26";   //2018-8-3 
      // "E2 34 53 7A 1E D9 7D B8 C5 02 36 0D B2 77 9E 5E 0F 32 71 17";   // 3/3/2019  
      // "C2 00 62 1D F7 ED AF 8B D1 D5 1D 24 D6 F0 A1 3A EB F1 B4 92";
      // "B6 F5 80 C8 B1 DA 61 C1 07 9D 80 42 D8 A9 1F AF 9F C8 96 7D";   //Apr19, 2019
      "03 D6 42 23 03 D1 0C 06 73 F7 E2 BD 29 47 13 C3 22 71 37 1B";   //Feb29, 2020


#endif  // FIREBASE_HTTP_CLIENT_H
