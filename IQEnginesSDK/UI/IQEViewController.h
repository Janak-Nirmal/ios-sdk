/*
 Copyright (c) 2011-2012 IQ Engines, Inc.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
*/

// --------------------------------------------------------------------------------
//
//  IQEViewController.h
//
// --------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import "IQE.h"
#import "IQEQuery.h"

@class IQEViewController;

// --------------------------------------------------------------------------------
//
// IQEViewControllerDelegate
//
// --------------------------------------------------------------------------------

@protocol IQEViewControllerDelegate <NSObject>
@optional

// Called when an image search has completed. Results are contained in the query object.
- (void) iqeViewController:(IQEViewController*)controller didCompleteSearch:(IQEQuery*)query;

// Called after the user selects an item in the history list.
- (void) iqeViewController:(IQEViewController*)controller didSelectItem:(IQEQuery*)query atIndex:(NSUInteger)index;

// The delegate should dismiss the view controller in this callback. The controller does not dismiss itself.
- (void) iqeViewControllerDidCancel:(IQEViewController*)controller;

@end

// --------------------------------------------------------------------------------
//
// IQEViewController
//
// View controller for the IQ Engines user interface.
//
// --------------------------------------------------------------------------------

@interface IQEViewController : UIViewController <IQEDelegate>
{
    id <IQEViewControllerDelegate> mDelegate;
    
    IQE* mIQE;
    
    IBOutlet UIView*          mPreviewView;
    IBOutlet UIButton*        mCameraButton;
    IBOutlet UIToolbar*       mToolBar;
    IBOutlet UIBarButtonItem* mBackButton;
    IBOutlet UIBarButtonItem* mHistoryButton;
}

// The designated initializers.
// If you subclass IQEViewController, you must call the super implementation of this method.
// Provide your IQ Engines key and secret parameters when using the IQESearchTypeRemoteSearch type.

- (id)initWithParameters:(IQESearchType)searchType;
- (id)initWithParameters:(IQESearchType)searchType apiKey:(NSString*)key apiSecret:(NSString*)secret;

// Set key and secret pair after initialization.
- (void) setApiKey:(NSString*)key apiSecret:(NSString*)secret;

// Actions for events.
- (IBAction)onCameraButton:(id)sender;
- (IBAction)onCancel:(id)sender;
- (IBAction)onHistory:(id)sender;

@property(nonatomic, assign) id<IQEViewControllerDelegate> delegate;

@property(nonatomic, assign) BOOL autoDetection;    // Automatic local detection. default is YES
@property(nonatomic, assign) BOOL hidesBackButton;  // default is NO.
@property(nonatomic, assign) BOOL locationEnabled;  // default is NO.

@end

// --------------------------------------------------------------------------------
