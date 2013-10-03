/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
 * The origin of this IDL file is
 * https://dvcs.w3.org/hg/IndexedDB/raw-file/tip/Overview.html
 *
 * Copyright © 2012 W3C® (MIT, ERCIM, Keio), All Rights Reserved. W3C
 * liability, trademark and document use rules apply.
 */

interface IDBKeyRange {
  [Throws]
  readonly attribute any     lower;
  [Throws]
  readonly attribute any     upper;
  [Constant]
  readonly attribute boolean lowerOpen;
  [Constant]
  readonly attribute boolean upperOpen;
  [Creator, Throws]
  static IDBKeyRange only (any value);
  [Creator, Throws]
  static IDBKeyRange lowerBound (any lower, optional boolean open = false);
  [Creator, Throws]
  static IDBKeyRange upperBound (any upper, optional boolean open = false);
  [Creator, Throws]
  static IDBKeyRange bound (any lower, any upper, optional boolean lowerOpen = false, optional boolean upperOpen = false);
};