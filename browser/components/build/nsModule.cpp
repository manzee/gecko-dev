/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: NPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Joe Hewitt <hewitt@netscape.com> (Original Author)
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the NPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the NPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "nsIGenericFactory.h"

#include "nsBrowserCompsCID.h"
#include "nsBookmarksService.h"
#ifdef XP_WIN
#include "nsWindowsHooks.h"
#endif
#include "nsProfileMigrator.h"
#include "nsDogbertProfileMigrator.h"
#include "nsOperaProfileMigrator.h"
#include "nsPhoenixProfileMigrator.h"
#include "nsSeamonkeyProfileMigrator.h"
#ifdef XP_WIN
#include "nsIEProfileMigrator.h"
#elif defined(XP_MACOSX)
#include "nsSafariProfileMigrator.h"
#include "nsOmniWebProfileMigrator.h"
#include "nsMacIEProfileMigrator.h"
#endif

/////////////////////////////////////////////////////////////////////////////

NS_GENERIC_FACTORY_CONSTRUCTOR_INIT(nsBookmarksService, Init)
#ifdef XP_WIN
NS_GENERIC_FACTORY_CONSTRUCTOR(nsWindowsHooks)
#endif

NS_GENERIC_FACTORY_CONSTRUCTOR(nsProfileMigrator)
NS_GENERIC_FACTORY_CONSTRUCTOR(nsDogbertProfileMigrator)
NS_GENERIC_FACTORY_CONSTRUCTOR(nsOperaProfileMigrator)
NS_GENERIC_FACTORY_CONSTRUCTOR(nsPhoenixProfileMigrator)
NS_GENERIC_FACTORY_CONSTRUCTOR(nsSeamonkeyProfileMigrator)
#ifdef XP_WIN
NS_GENERIC_FACTORY_CONSTRUCTOR(nsIEProfileMigrator)
#elif defined(XP_MACOSX)
NS_GENERIC_FACTORY_CONSTRUCTOR(nsSafariProfileMigrator)
NS_GENERIC_FACTORY_CONSTRUCTOR(nsOmniWebProfileMigrator)
NS_GENERIC_FACTORY_CONSTRUCTOR(nsMacIEProfileMigrator)
#endif
/////////////////////////////////////////////////////////////////////////////

static const nsModuleComponentInfo components[] =
{
#ifdef XP_WIN
  { NS_IWINDOWSHOOKS_CLASSNAME,
    NS_IWINDOWSHOOKS_CID,
    NS_IWINDOWSHOOKS_CONTRACTID,
    nsWindowsHooksConstructor },
#endif
  { "Bookmarks",
    NS_BOOKMARKS_SERVICE_CID,
    NS_BOOKMARKS_SERVICE_CONTRACTID,
    nsBookmarksServiceConstructor },

  { "Bookmarks",
    NS_BOOKMARKS_SERVICE_CID,
    NS_BOOKMARKS_DATASOURCE_CONTRACTID,
    nsBookmarksServiceConstructor },

  { "Profile Migrator",
    NS_PROFILEMIGRATOR_CID,
    NS_PROFILEMIGRATOR_CONTRACTID,
    nsProfileMigratorConstructor },

#ifdef XP_WIN
  { "Internet Explorer (Windows) Profile Migrator",
    NS_WINIEPROFILEMIGRATOR_CID,
    NS_BROWSERPROFILEMIGRATOR_CONTRACTID_PREFIX "ie",
    nsIEProfileMigratorConstructor },

#elif defined(XP_MACOSX)
  { "Safari Profile Migrator",
    NS_SAFARIPROFILEMIGRATOR_CID,
    NS_BROWSERPROFILEMIGRATOR_CONTRACTID_PREFIX "safari",
    nsSafariProfileMigratorConstructor },

  { "Internet Explorer (Macintosh) Profile Migrator",
    NS_MACIEPROFILEMIGRATOR_CID,
    NS_BROWSERPROFILEMIGRATOR_CONTRACTID_PREFIX "macie",
    nsMacIEProfileMigratorConstructor },

  { "OmniWeb Profile Migrator",
    NS_OMNIWEBPROFILEMIGRATOR_CID,
    NS_BROWSERPROFILEMIGRATOR_CONTRACTID_PREFIX "omniweb",
    nsOmniWebProfileMigratorConstructor },
#endif

  { "Opera Profile Migrator",
    NS_OPERAPROFILEMIGRATOR_CID,
    NS_BROWSERPROFILEMIGRATOR_CONTRACTID_PREFIX "opera",
    nsOperaProfileMigratorConstructor },

  { "Phoenix Profile Migrator",
    NS_PHOENIXPROFILEMIGRATOR_CID,
    NS_BROWSERPROFILEMIGRATOR_CONTRACTID_PREFIX "phoenix",
    nsPhoenixProfileMigratorConstructor },

  { "Seamonkey Profile Migrator",
    NS_SEAMONKEYPROFILEMIGRATOR_CID,
    NS_BROWSERPROFILEMIGRATOR_CONTRACTID_PREFIX "seamonkey",
    nsSeamonkeyProfileMigratorConstructor },

  { "Netscape 4.x Profile Migrator",
    NS_DOGBERTPROFILEMIGRATOR_CID,
    NS_BROWSERPROFILEMIGRATOR_CONTRACTID_PREFIX "dogbert",
    nsDogbertProfileMigratorConstructor }
};

NS_IMPL_NSGETMODULE(nsBrowserCompsModule, components)

