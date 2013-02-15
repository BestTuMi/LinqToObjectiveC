//
//  NSArray+LinqExtensions.h
//  LinqToObjectiveC
//
//  Created by Colin Eberhardt on 02/02/2013.
//  Copyright (c) 2013 Colin Eberhardt. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef BOOL (^Predicate)(id);

typedef BOOL (^Condition)(id);

typedef id (^Selector)(id);

typedef id (^Accumulator)(id, id);

/**
 Various NSArray extensions that provide a Linq-style query API
 */
@interface NSArray (LinqExtensions)

/** Filters a sequence of values based on a predicate.
 
 @param predicate The function to test each source element for a condition.
 @return An array that contains elements from the input sequence that satisfy the condition.
 */
- (NSArray*) where:(Predicate)predicate;

/** Projects each element of a sequence into a new form.
 
 @param selector Projects each element of a sequence into a new form.
 @return An array whose elements are the result of invoking the transform function on each element of source.
 */
- (NSArray*) select:(Selector)selector;

/** Sorts the elements of a sequence in ascending order.
 
 @return An array whose elements are sorted in ascending order.
 */
- (NSArray*) sort;

/** Sorts the elements of a sequence in ascending order by using a specified keySelector.
 
 @param keySelector A selector that provides the 'key' which the array should by sorted by. 
 @return An array whose elements are sorted in ascending order.
 */
- (NSArray*) sort:(Selector)keySelector;

/** Filters the elements of an an array based on a specified type.
 
 @param type The type to filter the elements of the sequence on.
 @return An array whose elements are all of the given type.
 */
- (NSArray*) ofType:(Class)type;

/** Projects each element of a sequence to an NSArray and flattens the resulting sequences into one sequence.
 
 @param transform A transform function to apply to each element, this should return an NSArray.
 @return An array whose elements are the result of invoking the one-to-many transform function on each element of the input sequence.
 */
- (NSArray*) selectMany:(Selector)transform;

/** Returns distinct elements from a sequence.
 
 @return An array of distinct elements.
 */
- (NSArray*) distinct;

/** Applies an accumulator function over a sequence.
 
 @param accumulator An accumulator function to be invoked on each element.
 @return The final accumulator value.
 */
- (id) aggregate:(Accumulator)accumulator;

/** Returns the first item from the source array, or nil if the array is empty.
 
 @return The first item from the source array, or nil if the array is empty.
 */
- (id) firstOrNil;

/** Returns the last item from the source array, or nil if the array is empty.
 
 @return The last item from the source array, or nil if the array is empty.
 */
- (id) lastOrNil;

/** Bypasses a specified number of elements in an array and then returns the remaining elements.
 
 @param count The number of elements to bypass.
 @return An array that contains the elements that occur after the specified index in the input array.
 */
- (NSArray*) skip:(NSUInteger)count;

/** Returns a specified number of contiguous elements from the start of an array.
 
 @param count The number of elements to take.
 @return An array that contains the specified number of elements from the start of the input array.
 */
- (NSArray*) take:(NSUInteger)count;

/** Determines whether all the element of the array satisfies a condition.
 
 @param condition The condition to test elements against.
 @return Whether all the element of the array satisfies a condition.
 */
- (BOOL) all:(Condition)condition;

/** Determines whether any the element of the array satisfies a condition.
 
 @param condition The condition to test elements against.
 @return Whether any the element of the array satisfies a condition.
 */
- (BOOL) any:(Condition)condition;


@end
