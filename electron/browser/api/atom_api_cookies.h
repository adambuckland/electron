// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ELECTRON_BROWSER_API_ATOM_API_COOKIES_H_
#define ELECTRON_BROWSER_API_ATOM_API_COOKIES_H_

#include <string>

#include "electron/browser/api/trackable_object.h"
#include "base/callback.h"
#include "native_mate/handle.h"
#include "net/cookies/canonical_cookie.h"

namespace base {
class DictionaryValue;
}

namespace content {
class BrowserContext;
}

namespace net {
class URLRequestContextGetter;
}

namespace atom {

namespace api {

class Cookies : public mate::TrackableObject<Cookies> {
 public:
  enum Error {
    SUCCESS,
    FAILED,
  };

  using GetCallback = base::Callback<void(Error, const net::CookieList&)>;
  using SetCallback = base::Callback<void(Error)>;

  static mate::Handle<Cookies> Create(v8::Isolate* isolate,
                                      content::BrowserContext* browser_context);

  // mate::TrackableObject:
  static void BuildPrototype(v8::Isolate* isolate,
                             v8::Local<v8::ObjectTemplate> prototype);

 protected:
  explicit Cookies(content::BrowserContext* browser_context);
  ~Cookies();

  void Get(const base::DictionaryValue& filter, const GetCallback& callback);
  void Remove(const GURL& url, const std::string& name,
              const base::Closure& callback);
  void Set(const base::DictionaryValue& details, const SetCallback& callback);

 private:
  net::URLRequestContextGetter* request_context_getter_;

  DISALLOW_COPY_AND_ASSIGN(Cookies);
};

}  // namespace api

}  // namespace atom

#endif  // ELECTRON_BROWSER_API_ATOM_API_COOKIES_H_