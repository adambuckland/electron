// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ELECTRON_BROWSER_WINDOW_LIST_OBSERVER_H_
#define ELECTRON_BROWSER_WINDOW_LIST_OBSERVER_H_

namespace atom {

class NativeWindow;

class WindowListObserver {
 public:
  // Called immediately after a window is added to the list.
  virtual void OnWindowAdded(NativeWindow* window) {}

  // Called immediately after a window is removed from the list.
  virtual void OnWindowRemoved(NativeWindow* window) {}

  // Called when a window close is cancelled by beforeunload handler.
  virtual void OnWindowCloseCancelled(NativeWindow* window) {}

  // Called immediately after all windows are closed.
  virtual void OnWindowAllClosed() {}

 protected:
  virtual ~WindowListObserver() {}
};

}  // namespace atom

#endif  // ELECTRON_BROWSER_WINDOW_LIST_OBSERVER_H_