//
//  MPAutotypeEnvironment.h
//  MacPass
//
//  Created by Michael Starke on 15.01.20.
//  Copyright © 2020 HicknHack Software GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KPKEntry;
@class MPAutotypeContext;

@interface MPAutotypeEnvironment : NSObject

/**
 The selected entry, if Autotype is run only for a single entry.
 If autotype should search for entries, set this to nil.
 */
@property (readonly, weak, nullable) KPKEntry *preferredEntry;
@property (readonly) pid_t pid; // the PID of the target application to which the key strokes should be sent
@property (readonly, copy) NSString *windowTitle; /// The window title of the target application.
@property (readonly) BOOL hidden; /// If set to YES, MacPass was hidden when autotype was initiated
@property (readonly) BOOL isSelfTargeting; /// If MacPass should autotype to itself, YES, otherwise NO
@property (readonly) NSString *overrideSequence; /// If set, this sequence is used for running the command regardless of the matched one
@property (readonly) BOOL globalAutotype; /// YES, if autotype is run as global autotype, NO otherwise

+ (instancetype)environmentWithTargetApplication:(NSRunningApplication * _Nullable)targetApplication entry:(KPKEntry * _Nullable)entry overrideSequence:(NSString * _Nullable)overrideSequence;

/// Create a environment for the autotype execution capturing the current exection context
/// @param targetApplication the application to target, supply nil to use the front most application (for e.g. Global Autotype)
/// @param entry the entry to use, if one is preferred (e.g. when being invoked via Perform Autotype)
/// @param overrdieSequence a custom sequence that should take precedence over any provided by the entry
- (instancetype)initWithTargetApplication:(NSRunningApplication * _Nullable)targetApplication entry:(KPKEntry * _Nullable)entry overrideSequence:(NSString * _Nullable)overrdieSequence NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
