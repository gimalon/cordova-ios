//
//  CDVMesasgesAppViewController.h
//  CordovaLib
//
//  Created by Simon Heinzle on 22/09/16.
//
//

#ifndef CDVMessagesAppViewController_h
#define CDVMessagesAppViewController_h

#import <UIKit/UIKit.h>
#import <Foundation/NSJSONSerialization.h>
#import "CDVAvailability.h"
#import "CDVInvokedUrlCommand.h"
#import "CDVCommandDelegate.h"
#import "CDVCommandQueue.h"
#import "CDVScreenOrientationDelegate.h"
#import "CDVPlugin.h"
#import "CDVWebViewEngineProtocol.h"
#import <Messages/Messages.h>

@interface CDVMessageAppViewController : MSMessagesAppViewController {
@protected
    id <CDVWebViewEngineProtocol> _webViewEngine;
@protected
    id <CDVCommandDelegate> _commandDelegate;
@protected
    CDVCommandQueue* _commandQueue;
    NSString* _userAgent;
}

@property (nonatomic, readonly, weak) IBOutlet UIView* webView;

@property (nonatomic, readonly, strong) NSMutableDictionary* pluginObjects;
@property (nonatomic, readonly, strong) NSDictionary* pluginsMap;
@property (nonatomic, readonly, strong) NSMutableDictionary* settings;
@property (nonatomic, readonly, strong) NSXMLParser* configParser;

@property (nonatomic, readwrite, copy) NSString* configFile;
@property (nonatomic, readwrite, copy) NSString* wwwFolderName;
@property (nonatomic, readwrite, copy) NSString* startPage;
@property (nonatomic, readonly, strong) CDVCommandQueue* commandQueue;
@property (nonatomic, readonly, strong) id <CDVWebViewEngineProtocol> webViewEngine;
@property (nonatomic, readonly, strong) id <CDVCommandDelegate> commandDelegate;

/**
 The complete user agent that Cordova will use when sending web requests.
 */
@property (nonatomic, readonly) NSString* userAgent;

/**
 The base user agent data that Cordova will use to build its user agent.  If this
 property isn't set, Cordova will use the standard web view user agent as its
 base.
 */
@property (nonatomic, readwrite, copy) NSString* baseUserAgent;

/**
 The address of the lock token used for controlling access to setting the user-agent
 */
@property (nonatomic, readonly) NSInteger* userAgentLockToken;

- (UIView*)newCordovaViewWithFrame:(CGRect)bounds;

- (NSString*)appURLScheme;
- (NSURL*)errorURL;

- (NSArray*)parseInterfaceOrientations:(NSArray*)orientations;
- (BOOL)supportsOrientation:(UIInterfaceOrientation)orientation;

- (id)getCommandInstance:(NSString*)pluginName;
- (void)registerPlugin:(CDVPlugin*)plugin withClassName:(NSString*)className;
- (void)registerPlugin:(CDVPlugin*)plugin withPluginName:(NSString*)pluginName;

- (void)parseSettingsWithParser:(NSObject <NSXMLParserDelegate>*)delegate;

@end

#endif /* CDVMesasgesAppViewController_h */
