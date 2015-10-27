# CocoaOneP

CocoaOneP is a bindings library for the Exosite One Platform.

[![Version](http://cocoapod-badges.herokuapp.com/v/CocoaOneP/badge.png)](http://cocoadocs.org/docsets/CocoaOneP)
[![Platform](http://cocoapod-badges.herokuapp.com/p/CocoaOneP/badge.png)](http://cocoadocs.org/docsets/CocoaOneP)

[![Build Status](https://travis-ci.org/exosite-labs/cocoaonep.svg)](https://travis-ci.org/exosite-labs/cocoaonep)

The complete [Exosite One Platform API](https://github.com/exosite/docs) covers a lot of
ground.  This set of bindings only covers the following lower-level APIs:
- Remote Procedure Call API

You need to be at least partially familar with the low-level APIs to use this library well.

## Usage

To run the example project; clone the repo, and run `pod install` from the Project directory first.

More examples are needed badly, I know. Help.

We are in the progress of adding appledoc to all the headers.


## Requirements

CocoaOneP requires Xcode 7.1, targeting either iOS 7.0 and above, or Mac OS 10.8 Mountain Lion.
It also depends on [AFNetworking 3.0](https://github.com/AFNetworking/AFNetworking).

## Installation with CocoaPods

CocoaOneP is available through [CocoaPods](http://cocoapods.org), to install
it simply add the following line to your Podfile:

```ruby
pod "CocoaOneP"
```

If you don't want or need everything, you can install each of the API groups as submodules.
For example, if all you need is the RPC API:

```ruby
pod "CocoaOneP/RPC"
```


## License

License is BSD, Copyright 2014, Exosite LLC. See the LICENSE file for more info.

