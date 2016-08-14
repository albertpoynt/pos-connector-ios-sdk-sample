//
//  PoyntPOSConnectionManager.h
//  sdk_example_swift
//
//  Created by Eric McConkie on 8/11/16.
//  Copyright © 2016 com.poynt. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PoyntTransactionObject;
@class PoyntTransactionAmounts;
@class PoyntPaymentObject;
@class PoyntTransactionResponseObject;
typedef enum {
    Undefined,
    AuthorizeSales,
    AuthorizeVoid,
    AuthorizeRefund,
    AuthorizePair,
    AuthorizePreSales,
    AuthorizeVoidPreSales,
    AuthorizeCapture
} Api;



typedef void(^OnTransactionResponse)(PoyntTransactionResponseObject *data, Api type) ;
typedef void(^OnError)(NSError *error) ;

@interface PoyntPOSConnectionManager : NSObject
@property(nonatomic,strong) NSString *pairingCode;
@property(nonatomic,strong) NSString *url;
@property(nonatomic,strong) NSString *clientName;
@property(nonatomic) NSInteger timeout;
@property(nonatomic) BOOL paired;

@property (readwrite,copy) OnTransactionResponse onTransactionResponse;
@property (readwrite,copy) OnError onError;


-(void)authorizeCapture:(PoyntTransactionObject *)transaction;
-(void)authorizePairing:(NSString *)code;
-(void)authorizePreSales:(PoyntPaymentObject *)payment;
-(void)authorizeRefund:(PoyntTransactionObject *)transaction ;
-(void)authorizeSales:(PoyntPaymentObject *)payment ;
-(void)authorizeVoid:(PoyntTransactionObject *)transaction;
-(void)authorizeVoidPreSales:(PoyntTransactionObject *)transaction ;

@end