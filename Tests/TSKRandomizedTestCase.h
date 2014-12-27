//
//  TSKRandomizedTestCase.h
//  Task
//
//  Created by Prachi Gauriar on 10/30/2014.
//  Copyright (c) 2014 Two Toasters, LLC.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

@import XCTest;

#import <URLMock/UMKTestUtilities.h>
#import <Task/Task.h>

#import "TSKTestTask.h"


/*!
 TSKRandomizedTestCases override +setUp to call srandomdev() and -setUp to generate and log a random
 seed value before calling srandom(). Subclasses that override +setUp or -setUp should invoke the
 superclass implementation.

 It also has a notification center that may be used with TSKWorkflows to post notifications on.
 */
@interface TSKRandomizedTestCase : XCTestCase

@property (nonatomic, strong) NSNotificationCenter *notificationCenter;

- (NSString *)defaultNameForTask:(TSKTask *)task;

- (TSKWorkflow *)workflowForNotificationTesting;

- (XCTestExpectation *)expectationForNotification:(NSString *)notificationName task:(TSKTask *)task;
- (XCTestExpectation *)expectationForNotification:(NSString *)notificationName workflow:(TSKWorkflow *)workflow block:(void (^)(NSNotification *))block;

@end
