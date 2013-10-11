
<!doctype html>
<html>
<head>
    <meta charset="UTF-8">
    <link rel="icon" type="image/png" href="https://www.openlearning.com/media-455534c/images/favicon.png">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="apple-mobile-web-app-capable" content="yes" />
    <meta name="apple-mobile-web-app-status-bar-style" content="black">
    <link rel="apple-touch-icon" href="https://www.openlearning.com/media-455534c/images/openlearning-icon.png"/>


    <title>

        
            
                hunter.h - 
            
        
        
            Computing 2 - 
        
        Files_v0.02 - FuryOfDracula - OpenLearning

    </title>

    <link href="https://www.openlearning.com/media-455534c/new/css/style.css" rel="stylesheet" type="text/css">
    <link href="https://www.openlearning.com/media-455534c/lib/bootstrap-modal/bootstrap-modal.css" rel="stylesheet" type="text/css">




<link rel="stylesheet" type="text/css" href="https://www.openlearning.com/media-455534c/new/css/pages/courseTheme1.css">
<style type="text/css">
/* Customised styling for banner */


body {
	
	background-color: #536d8b;
	
	background-repeat: no-repeat;
	
	background-attachment: fixed;
	background-position: left center;
}

#site-container {
	background: inherit;
}

.page-section {
	background: none;
}

#course-banner {
	
		
	background-image: url(https://openlearning-cdn.s3.amazonaws.com/course__unsw_courses_COMP19272013S2__course-banner-1374738956.jpg);
	filter: none;
		
	

	
		
			text-align: left;
		
	

	background-repeat: no-repeat;
	background-size: cover;
}


#course-banner-link:hover {
	text-decoration: none;
}

.no-pad-top {
	padding-top: 0;
}


.banner-title {
	color: #ffffff !important;
}


.progress {
	height: inherit;
}

/* our beautiful ribbon */
.ribbonwrapper {
    margin: 0px auto;
    position: relative;
    z-index: 90;
}

.ribbon-wrapper-blue {
    width: 85px;
    height: 88px;
    overflow: hidden;
    position: absolute;
    top: -3px;
    left: -3px;
}

.ribbon-blue {
    font: bold 14px Sans-Serif;
    color: #fff;
    text-align: center;
    letter-spacing:1px;
    text-shadow:1px -1px 3px rgba(0,0,0,0.5) ;
    -webkit-transform: rotate(-45deg);
    -moz-transform:    rotate(-45deg);
    -ms-transform:     rotate(-45deg);
    -o-transform:      rotate(-45deg);
    position: relative;
    padding: 6px 0;
    left: -28px;
    top: 18px;
    width: 120px;
    background: #d01616;
    color: #fff;
    -webkit-box-shadow: 0px 0px 3px rgba(0,0,0,0.3);
    -moz-box-shadow:    0px 0px 3px rgba(0,0,0,0.3);
    box-shadow:         0px 0px 3px rgba(0,0,0,0.3);
}

.ribbon-blue:before, .ribbon-blue:after {
    content: "";
    border-top:   3px solid #ad1717;
    border-left:  3px solid transparent;
    border-right: 3px solid transparent;
    position:absolute;
    bottom: -3px;
}
.ribbon-blue:before {left: 0;}
.ribbon-blue:after {right: 0;}

#course-admin-link:hover, #teacher-admin-link:hover {
	background: white;
}
#course-admin-link ul li, #teacher-admin-link ul li {
	padding-left: 10px;
	border: none;
}

#course-admin-link ul li.active, #teacher-admin-link ul li.active {
	background: #efefef;
}

#course-admin-link ul li:hover, #teacher-admin-link ul li:hover {
	background: #f3f3f3;
}

.course-admin-nav-icon {
	display: inline-block;
	width: 12px;
	margin-right: 5px;
	text-align: center;
}

.course-admin-nav-icon i {
	color: #666;
}

#course-live-ribbon a {
	color: white;
}
</style>

    <style type="text/css" media="screen">
        a#activityURL, a#submissionLink {
            color: #42719E;
        }
        a#activityURL:hover, a#submissionLink:hover {
            text-decoration: underline;
        }

        #social-content-box {
           margin-top: 30px;
           text-align: center;
           }
        #invite-friends-button {
           text-align: center;
           }

           #pageFooter {
               clear: both;
           }
    </style>


    <link href="//fonts.googleapis.com/css?family=Source+Sans+Pro" rel="stylesheet" type="text/css">
    <link href="//fonts.googleapis.com/css?family=Source+Sans+Pro:400italic" rel="stylesheet" type="text/css">
    <link href="//fonts.googleapis.com/css?family=Source+Sans+Pro:400italic" rel="stylesheet" type="text/css">
    <link href="//fonts.googleapis.com/css?family=Source+Sans+Pro:600" rel="stylesheet" type="text/css">
    <link href="//fonts.googleapis.com/css?family=Source+Sans+Pro:700" rel="stylesheet" type="text/css">
    <script src="https://www.openlearning.com/media-455534c/new/js/modernizr.js"></script>
    <script src="https://www.openlearning.com/media-455534c/new/js/modernizr.custom.js"></script>
    <script charset="utf-8">
        var currentCourse = 'unsw/courses/COMP1927-2013S2';
        var currentCohort = 'unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort';
        window.OpenLearningUserData = {
            courseAdmin: false,

            isMyProfilePage: 'false' == 'true',
            profileName: 'lucas.pickup',
            fullName: 'Lucas Pickup',
            avatar24: 'https://openlearning-cdn.s3.amazonaws.com/lucas.pickup-avatar-24-ts1375065581.jpg',
            avatar48: 'https://openlearning-cdn.s3.amazonaws.com/lucas.pickup-avatar-48-ts1375065579.jpg',
            timezoneOffset: 660.0

        };

        var baseMedia = 'https://www.openlearning.com/media-455534c/';
        var siteURL = 'https://www.openlearning.com';

    </script>

    <script src="https://www.openlearning.com/media-455534c/scripts/min/ol-anon.min.js"></script>
    

<!-- start OpenLearning Metrics -->
<script type="text/javascript">
    var OpenLearningMetrics = {
        loadTime: new Date().getTime(),
        itemsClicked: [],
        scrollDistance: 0,
        windowSize: {width: 0, height: 0},
        keysPressed: 0
    };

    JS.require('API', function() {
        var inactiveTime = 0;
        var blurTime = null;
        var remoteAddress = "58.111.148.185";

        $(document).scroll(function(evt) {
            OpenLearningMetrics.scrollDistance = Math.max(OpenLearningMetrics.scrollDistance, $(document).scrollTop());
        }).keypress(function() {
            OpenLearningMetrics.keysPressed++;
        });

        $(window).load(function() {
            OpenLearningMetrics.windowSize.width  = $(window).width();
            OpenLearningMetrics.windowSize.height = $(window).height();
        });

        $(window).resize(function() {
            OpenLearningMetrics.windowSize.width  = $(window).width();
            OpenLearningMetrics.windowSize.height = $(window).height();
        });

        $(window).on('click', function(evt) {
            var $target = $(evt.target);
            var classes = $target[0].className;
            var classList = [];

            if (classes !== '' && classes.split) {
                classList = classes.split(/\s+/);
            }
            
            OpenLearningMetrics.itemsClicked.push({
                id: $target.attr('id'),
                name: $target.prop('nodeName'),
                classes: classList,
                x: evt.pageX,
                y: evt.pageY,
                time: new Date().getTime() - OpenLearningMetrics.loadTime
            });
        }).on('focus', function() {
            var focusTime = new Date().getTime();

            if (blurTime !== null) {
                inactiveTime += (focusTime - blurTime);
            }
            
            blurTime = null;
        }).on('blur', function() {
            blurTime = new Date().getTime();
        }).on('unload', function() {
            var query = window.location.search.slice(1).split('&');
            var suffix = '';
            $.each(query, function(i, pair) {
                var parts = pair.split('=');
                if (parts[0] === 'action' && parts[1] !== 'view') {
                    suffix = '+' + parts[1]
                }
            });

            var unloadTime = new Date().getTime();
            var activeTime = (unloadTime - OpenLearningMetrics.loadTime) - inactiveTime;
            var data = {
                path: window.location.pathname + suffix,
                data: JSON.stringify({
                    remoteAddress: remoteAddress,
                    loadTime: OpenLearningMetrics.loadTime,
                    unloadTime: unloadTime,
                    activeTime: activeTime,
                    inactiveTime: inactiveTime,
                    itemsClicked: OpenLearningMetrics.itemsClicked,
                    scrollDistance: OpenLearningMetrics.scrollDistance + OpenLearningMetrics.windowSize.height,
                    windowSize: OpenLearningMetrics.windowSize,
                    keysPressed: OpenLearningMetrics.keysPressed
                })
            };
            
            API.post('save-metric/pageLeave/', data, {async: false});
        });
    });
</script>
<!-- end OpenLearning Metrics -->
<script type="text/javascript">(function(c,a){window.mixpanel=a;var b,d,h,e;b=c.createElement("script");b.type="text/javascript";b.async=!0;b.src=("https:"===c.location.protocol?"https:":"http:")+
        '//cdn.mxpnl.com/libs/mixpanel-2.2.min.js';d=c.getElementsByTagName("script")[0];d.parentNode.insertBefore(b,d);a._i=[];a.init=function(b,c,f){function d(a,b){var c=b.split(".");2==c.length&&(a=a[c[0]],b=c[1]);a[b]=function(){a.push([b].concat(Array.prototype.slice.call(arguments,0)))}}var g=a;"undefined"!==typeof f?g=a[f]=[]:
        f="mixpanel";g.people=g.people||[];h=['disable','track','track_pageview','track_links','track_forms','register','register_once','unregister','identify','alias','name_tag','set_config','people.set','people.set_once','people.increment','people.track_charge','people.append'];for(e=0;e<h.length;e++)d(g,h[e]);a._i.push([b,c,f])};a.__SV=1.2;})(document,window.mixpanel||[]);
    
    mixpanel.init("2d7613ce258a58514e30c1e49f912e34");
    
</script><!-- end Mixpanel -->
<script charset="utf-8">
    JS.require('OpenLearning', 'jQuery.ui', 'Instrumentation', 'Utilities', function() {
        
        var isNewAccount = !!Utilities.getCookie("OL-NewAccount");
        if (isNewAccount) {
            mixpanel.alias("lucas.pickup")
            Utilities.deleteCookie("OL-NewAccount");
        }
        mixpanel.name_tag("lucas.pickup");
        mixpanel.identify("lucas.pickup");

        Instrumentation.addProperties({
            isLoggedIn: true,
            isFacebookConnected: false
        });
        
        
        Instrumentation.addProperties({
            course: "COMP1927-2013S2",
            courseCategory: "ENG",
            coursePath: "unsw/courses/COMP1927-2013S2",
            courseIsPaid: true,
            courseDisplayed: false,
            courseInstitutionLink: true
        });
        
        
        Instrumentation.addProperties({
            cohort: "unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort".split('/').pop(),
            cohortPath: "unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort",
            isCourseAdmin: false,
            enrolDate: "2013-07-29T02:17:27.504Z",
            enrolledDays: 74.0
        });
        
        
        Instrumentation.addProperties({
            pagePath: "unsw/courses/COMP1927-2013S2/FuryOfDracula/Files_v0.02/hunter.h"
        });
        
        // Record instrumentation events handed to us by the server.
        var serverEventString = Utilities.getCookie("OL-Instrumentation")
        if (serverEventString) {
            Utilities.deleteCookie("OL-Instrumentation");
            //console.log("Warning: don't use instrumentation cookie right now - it's broken.");
            //var serverEvents = {};
            //try {
            //  serverEvents = JSON.parse(decodeURIComponent(serverEventString));
            //} catch (e) {
            //  console.error("Invalid JSON in instrumentation cookie: " + serverEventString);
            //}
            //$.each(serverEvents, function(event, props) { Instrumentation.track(event, props); });
        }
        $(document).ready(function() {
            $('a.instrumented').on('click', function(event) {
                Instrumentation.trackElement($(this), event, true);
            });
        });
    });
 </script>


    <script type="text/javascript" src="https://www.openlearning.com/media-455534c/lib/google-code-prettify/prettify.combined.js"></script>

    

    <script>
        JS.require( 'Markup', function() {
            var markupJS = new Markup();
        } );
    </script>

    <style type="text/css">
    .edit-menu i {
        font-size: 16px;
    }
    </style>

    <script type="text/javascript" charset="utf-8">
        JS.require('jQuery', function() {
            $(document).ready(function() {
                prettyPrint();

                var pageId = '523ffacdb919662b177a576f';
                var $subscriptionButton = $('#subscription-button');
                var currentSubscription = '';
                var isButton = $subscriptionButton.hasClass('btn');

                // We don't need abstraction here.
                var setCurrentSubscription = function(subscription) {
                    if (isButton) {
                        if (subscription == '' || subscription == 'none') {
                            $subscriptionButton.removeClass('btn-success')
                                               .addClass('btn-info')
                                               .html('Subscribe to Blog');
                        } else {
                            $subscriptionButton.removeClass('btn-info')
                                               .addClass('btn-success')
                                               .html('<i class="icon icon-ok"></i> Subscribed');
                        }
                    } else {
                        if (subscription == '' || subscription == 'none') {
                            $subscriptionButton.html('<i class="icon icon-globe"></i> Subscribe').removeClass('subscribed');
                        } else {
                            $subscriptionButton.html('<i class="icon icon-ok"></i> Subscribed').addClass('subscribed');
                        }
                    }
                    currentSubscription = subscription;
                };

                // Change the initial subscription in case we're already subscribed.
                setCurrentSubscription(currentSubscription);

                var previousSubscribeHtml;
                $subscriptionButton.click(function() {
                    $subscriptionButton.attr('disabled', 'disabled');
                    var subscriptionToSet;
                    if (currentSubscription == '' || currentSubscription == 'none') {
                        // then subscribe them
                        if (isButton) {
                            subscriptionToSet = 'page-edit';
                        } else {
                            subscriptionToSet = 'tree';
                        }
                    } else {
                        // unsubscribe them
                        subscriptionToSet = 'none';
                    }
                    $.ajax(siteURL + '/subscription/update/', {
                        'dataType': 'json',
                        'type': 'POST',
                        'data': {
                            'notificationType': subscriptionToSet,
                            'page': pageId
                        }
                    }).done(function() {
                        setCurrentSubscription(subscriptionToSet);
                    }).fail(function() {
                        alert('There was a problem changing your subscription.');
                    }).always(function() {
                        $subscriptionButton.removeAttr('disabled');
                    });
                }).hover(function() {
                    var $this = $(this);
                    if ($this.hasClass('subscribed')) {
                        previousSubscribeHtml = $this.html();
                        $this.html('Unsubscribe?');
                    }
                }, function() {
                    var $this = $(this);
                    if ($this.hasClass('subscribed')) {
                        $this.html(previousSubscribeHtml);
                    }
                });
            });
        });
    </script>
    

</head>
<body>

    <div id="mobile-left-panel" class="mobile-slide-panel visible-phone">
        
        <ul class="mobile-user-menu">
            <li style="height: 42px;">
                <form action="https://www.openlearning.com/search/" method="get" accept-charset="utf-8">
                    <input type="text" name="containsText" value="" placeholder="Search..." style="width: 90%;">
                    <input type="hidden" name="course" value="unsw/courses/COMP1927-2013S2">
                </form>
            </li>
            <li>
                <img src="https://openlearning-cdn.s3.amazonaws.com/lucas.pickup-avatar-24-ts1375065581.jpg">
                <a href="https://www.openlearning.com/u/lucas.pickup">
                    Lucas Pickup 
                    <small style="font-size: 70%;">
                        View Profile
                    </small>
                </a>
                <ul class="user-submenu">
                    <li>
                        <a href="https://www.openlearning.com/accounts/account-settings/">
                            Account Settings
                        </a>
                    </li>
                    <li>
                        <a href="https://www.openlearning.com/accounts/notifications/#settings">
                            Notification Settings
                        </a>
                    </li>
                    <li>
                        <a href="https://www.openlearning.com/help">
                            Help / Report a Problem
                        </a>
                    </li>
        
        
        </ul>
        
        
        <hr>
        <h4>Course Navigation</h4>
        
        <div id="mobile-menu">
            
        </div>
        
            <form action="https://www.openlearning.com/accounts/logout/" id="logout-form" class="logout-form" method="post" accept-charset="utf-8">
                <div style='display:none'><input type='hidden' name='csrfmiddlewaretoken' value='gh5nG3jo9Oj5lIAE5AxQmUARkInGjZRS' /></div>
                <input type="submit" name="logout" class="logout-button" id="logout-button" value="Logout"/>
            </form>
        
    </div>
    <script type="text/javascript">
        JS.require('OpenLearning_mobile', function() {
            OpenLearning_mobile.init();
        });
    </script>


<div id="site-container">


    <header class="header stickyheader">
    <div class="container">
        <div class="row visible-phone mobile-header-row" id="mobile-header-row">
            
            <button type="button" id="mobile-nav-menu-btn" class="mobile-heading-item pull-left mobile-heading-button"><i class="icon-reorder"></i></button>
            
            <div class="mobile-heading-item pull-left">
                <a href="https://www.openlearning.com/" title="OpenLearning">
                    <img src="https://www.openlearning.com/media-455534c/images/openlearning-logo-header-mobile.png" alt="OpenLearning">
                </a>
            </div>

            
            <button type="button" id="mobile-courses-menu-btn" class="mobile-heading-item pull-right mobile-heading-button"><i class="icon-group"></i></button>

            <div class="mobile-heading-item mobile-heading-button pull-right" id="mobile-notifications-menu-btn">
                <span class="badge badge-warning notification-badge">4</span>
            </div>
            
        </div>

        <div class="row hidden-phone" id="desktop-header-row">
            <section class="span6 logo">
                <div class="pull-left">
                    <a href="https://www.openlearning.com/" title="OpenLearning">

                        <img src="https://www.openlearning.com/media-455534c/images/openlearning-logo-header-small.png" alt="OpenLearning" id="header-logo">
                    </a>
                </div>

                <div id="search-container" class="pull-left">
                    <form action="https://www.openlearning.com/search/" method="get" accept-charset="utf-8">
                        <input type="text" name="containsText" value="" placeholder="Search...">
                        <input type="hidden" name="course" value="unsw/courses/COMP1927-2013S2">
                    </form>
                </div>

            </section>
            <section class="span6 ">
                <nav id="main_menu_sticky">
                    <div id="headerbar-nav-container" class="nav-collapse collapse">

                        <ul class="nav nav-pills pull-right">
                            <li class="dropdown">
                                <a class="dropdown-toggle" data-toggle="dropdown" data-target="#" href="#">
                                    <div id="profile-container">
                                        <img id="header-profile-image" src="https://openlearning-cdn.s3.amazonaws.com/lucas.pickup-avatar-24-ts1375065581.jpg" alt="" border="0" class="profile-image" align="absmiddle" id="myAvatar24">
                                    </div>
                                </a>
                                <ul class="dropdown-menu profile-image-dropdown-menu">
                                    <li>
                                        <a href="https://www.openlearning.com/u/lucas.pickup">
                                            Lucas Pickup 
                                            <small style="font-size: 70%;">
                                                View Profile
                                            </small>
                                        </a>
                                    </li>
                                    <li class="divider"></li>
                                    <li>
                                        <a href="https://www.openlearning.com/accounts/account-settings/">
                                            Account Settings
                                        </a>
                                    </li>
                                    <li>
                                        <a href="https://www.openlearning.com/accounts/notifications/#settings">
                                            Notification Settings
                                        </a>
                                    </li>
                                    <li class="divider"></li>
                                    <li>
                                        <a href="https://www.openlearning.com/help">
                                            Help / Report a Problem
                                        </a>
                                    </li>
                                    <li class="divider"></li>
    
    
                                    <li>
                                        <form action="https://www.openlearning.com/accounts/logout/" id="logout-form" class="logout-form" method="post" accept-charset="utf-8">
                                            <div style='display:none'><input type='hidden' name='csrfmiddlewaretoken' value='gh5nG3jo9Oj5lIAE5AxQmUARkInGjZRS' /></div>
                                            <input type="submit" name="logout" class="logout-button" id="logout-button" value="Logout"/>
                                        </form>
                                    </li>
                                </ul>
                            </li>
                        </ul>
                        <ul class="nav nav-pills pull-right">
                            <li>
                                <a id="new-blog-entry-button">
                                    <span class="menu-item-text">
                                        Blog
                                    </span>
                                </a>
                            </li>

                            <li class="dropdown">
                                <a class="dropdown-toggle" data-toggle="dropdown" data-target="#" href="#">
                                    <span class="menu-item-text">
                                        Notifications
    
                                        <span class="badge badge-warning notification-badge">4</span>
    
                                    </span>
                                </a>
                                <ul class="notifications-dropdown-menu dropdown-menu" id="notifications-dropdown">
    
        
                                    <li>
                                        <a href="https://www.openlearning.com/notifications/go/?id=521e8dfab919662b1778677f">
                                            <div class="notification-preview">
                                                <img src="https://openlearning-cdn.s3.amazonaws.com/jerry.bell-avatar-48-ts1379323762.jpg" align="left">
                                                <span class="notificationDetails">
                                                    <strong>Jeremy Bell</strong>, <strong>Chris Fong</strong>, <strong>Clancy Rye</strong> commented: <br/><i>Pairings have been posted up ...</i><br/> on <strong>W10B - Tutorial and Lab</strong> in <strong>COMP1927-2013S2</strong> <small>(2013 Semester 2)</small>
                                                </span>
                                                <div style="clear: both;"></div>
                                            </div>
                                        </a>
                                    </li>
        
                                    <li>
                                        <a href="https://www.openlearning.com/notifications/go/?id=523f493fb919662b177a4e08">
                                            <div class="notification-preview">
                                                <img src="https://openlearning-cdn.s3.amazonaws.com/richard.buckland-avatar-48-ts1348830373.jpg" align="left">
                                                <span class="notificationDetails">
                                                    <strong>Richard Buckland</strong> has updated <br/>'<i> </i>'<br/> on <strong>Prac Exam warmup</strong> in <strong>COMP9024</strong> <small>(2013 session2)</small>
                                                </span>
                                                <div style="clear: both;"></div>
                                            </div>
                                        </a>
                                    </li>
        
                                    <li>
                                        <a href="https://www.openlearning.com/notifications/go/?id=521db8fab919662b17784f39">
                                            <div class="notification-preview">
                                                <img src="https://openlearning-cdn.s3.amazonaws.com/johndilanna-avatar-48-ts1374041610.jpg" align="left">
                                                <span class="notificationDetails">
                                                    <strong>John Di Lanna</strong>, <strong>Vincent Tran</strong> commented: <br/><i>Its all good now, I got it :)</i><br/> on <strong>Schedule</strong> in <strong>cpp1</strong> <small>(First Cohort)</small>
                                                </span>
                                                <div style="clear: both;"></div>
                                            </div>
                                        </a>
                                    </li>
        
                                    <li>
                                        <a href="https://www.openlearning.com/notifications/go/?id=521e458bb919662b177861cc">
                                            <div class="notification-preview">
                                                <img src="https://openlearning-cdn.s3.amazonaws.com/nasir.jamil-avatar-48-ts1377714974.jpg" align="left">
                                                <span class="notificationDetails">
                                                    <strong>Nasir Jamil</strong> commented: <br/><i>Hello, This is Nasir Jamil , ...</i><br/> on <strong>Home</strong> in <strong>cpp1</strong> <small>(First Cohort)</small>
                                                </span>
                                                <div style="clear: both;"></div>
                                            </div>
                                        </a>
                                    </li>
        
                                    <li class="divider"></li>
    
                                    <li>
                                        <a href="https://www.openlearning.com/accounts/notifications/">
                                            See all notifications
                                        </a>
                                    </li>
                                </ul>
                            </li>

                            <li class="dropdown">
                                <a class="dropdown-toggle" data-toggle="dropdown" href="#">
                                    <span class="menu-item-text">
                                        Courses
                                    </span>
                                </a>
                                <ul class="courses-dropdown-menu dropdown-menu" role="menu" id="courses-dropdown">
    
        
            
                                    <li>
                                        <a href="https://www.openlearning.com/unsw" style="overflow: hidden; text-overflow: ellipsis;">
                                            UNSW
                                        </a>
                                    </li>
            
        
        
                                    <li class="divider"></li>
        
    

    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/12s2COMP1927&amp;cohort=courses/12s2COMP1927/Cohorts/12s2" style="overflow: hidden; text-overflow: ellipsis;">
                                        COMP1927 12s2
                                        <small style="font-size: 70%;">2012 S2</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/COMP439568&amp;cohort=courses/COMP439568/Cohorts/FirstCohort" style="overflow: hidden; text-overflow: ellipsis;">
                                        COMP2121 2012 s2
                                        <small style="font-size: 70%;">First Cohort</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/Comp1917&amp;cohort=courses/Comp1917/Cohorts/12S1" style="overflow: hidden; text-overflow: ellipsis;">
                                        Comp1917 2012s1
                                        <small style="font-size: 70%;">12s1</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=unsw/courses/Computing1&amp;cohort=unsw/courses/Computing1/Cohorts/FirstCohort" style="overflow: hidden; text-overflow: ellipsis;">
                                        Computing 1
                                        <small style="font-size: 70%;">COMP1917 13S1</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/COMP070584&amp;cohort=courses/COMP070584/Cohorts/FirstCohort" style="overflow: hidden; text-overflow: ellipsis;">
                                        Computing 1.1
                                        <small style="font-size: 70%;">First Cohort</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=unsw/courses/COMP1927-2013S2&amp;cohort=unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort" style="overflow: hidden; text-overflow: ellipsis;">
                                        Computing 2
                                        <small style="font-size: 70%;">2013 Semester 2</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/Comp1927&amp;cohort=courses/Comp1927/Cohorts/2012Ol1" style="overflow: hidden; text-overflow: ellipsis;">
                                        Computing 2
                                        <small style="font-size: 70%;">2012-OL-1</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/COMP461394&amp;cohort=courses/COMP461394/Cohorts/Default" style="overflow: hidden; text-overflow: ellipsis;">
                                        Computing 3
                                        <small style="font-size: 70%;">Default</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=unsw/courses/COMP9024&amp;cohort=unsw/courses/COMP9024/Cohorts/2013Semester2" style="overflow: hidden; text-overflow: ellipsis;">
                                        Data Structures and Algorithms
                                        <small style="font-size: 70%;">2013 session2</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/COMP554397&amp;cohort=courses/COMP554397/Cohorts/Default" style="overflow: hidden; text-overflow: ellipsis;">
                                        MIT Introduction to Computer Science and Programming
                                        <small style="font-size: 70%;">Default</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/COMP585711&amp;cohort=courses/COMP585711/Cohorts/Default" style="overflow: hidden; text-overflow: ellipsis;">
                                        Machine Learning
                                        <small style="font-size: 70%;">Default</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/COMP087390&amp;cohort=courses/COMP087390/Cohorts/FirstCohort" style="overflow: hidden; text-overflow: ellipsis;">
                                        Magical Adventures in Recreational Computer Science
                                        <small style="font-size: 70%;">First Cohort</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=unsw/courses/MATH1231-2013S2&amp;cohort=unsw/courses/MATH1231-2013S2/Cohorts/2013Semester2" style="overflow: hidden; text-overflow: ellipsis;">
                                        Mathematics 1B
                                        <small style="font-size: 70%;">2013 Semester 2</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/COMP970327&amp;cohort=courses/COMP970327/Cohorts/FirstCohort" style="overflow: hidden; text-overflow: ellipsis;">
                                        Object-Oriented Programming (2012 S2)
                                        <small style="font-size: 70%;">First Cohort</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/cpp1&amp;cohort=courses/cpp1/Cohorts/FirstCohort" style="overflow: hidden; text-overflow: ellipsis;">
                                        Practical Programming! Part 1
                                        <small style="font-size: 70%;">First Cohort</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/MATH986984&amp;cohort=courses/MATH986984/Cohorts/Public1" style="overflow: hidden; text-overflow: ellipsis;">
                                        Problem Solving
                                        <small style="font-size: 70%;">public1</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/unsw/COMP3901&amp;cohort=courses/unsw/COMP3901/Cohorts/Default" style="overflow: hidden; text-overflow: ellipsis;">
                                        Reversing and Exploitation 
                                        <small style="font-size: 70%;">Default</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/BUS832911&amp;cohort=courses/BUS832911/Cohorts/Oct152012" style="overflow: hidden; text-overflow: ellipsis;">
                                        Services Marketing - Selling the Invisible
                                        <small style="font-size: 70%;">Oct15-2012</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/COMP870724&amp;cohort=courses/COMP870724/Cohorts/Default" style="overflow: hidden; text-overflow: ellipsis;">
                                        The Littlest Elf
                                        <small style="font-size: 70%;">Default</small>
                                        </a>
                                    </li>
        
    
        
                                    <li class="courseDropdownItem" data-cohort="">
                                        <a href="https://www.openlearning.com/courses/go/?course=courses/unsw/computing1&amp;cohort=courses/unsw/computing1/Cohorts/FirstCohort" style="overflow: hidden; text-overflow: ellipsis;">
                                        UNSW Computing 1 - The Art of Programming
                                        <small style="font-size: 70%;">First Cohort</small>
                                        </a>
                                    </li>
        
    
                                    <li class="divider"></li>
                                    <li>
                                        <a href="https://www.openlearning.com/courses/my/">
                                            View all my courses
                                        </a>
                                    </li>
    
                                    <li>
                                        <a href="https://www.openlearning.com/courses/">
                                            Find new courses
                                        </a>
                                    </li>
    
                                </ul>
                            </li>
                        </ul>

                    </div>
                </nav>
            </section>
        </div>
    </div>

    <script type="text/javascript" charset="utf-8">
    JS.require( 'jQuery', 'Blogging', function ($, Blogging) {
        $("#new-blog-entry-button").click(function(event) {
            event.preventDefault();

            Blogging.del('blogMinimized');
            if ($("#new-blog-container").length === 0) {
                Blogging.showBlogContainer(
                
                    "/u/lucas.pickup/blog",
                
                    "",
                    "global"
                );
            } else {
                Blogging.minimizeBlogContainer();
            }
        }); 
        $(function () {
            Blogging.loadDraftBlog(
            
                "/u/lucas.pickup/blog",
            
                "",
                "global"
            );
        });

        $('.courseHeadMenu').click(function(e) {
            e.preventDefault();
            e.stopPropagation();

            var $this = $(this);

            $('.courseHeadMenu').not($this).removeClass('highlight');
            $this.toggleClass('highlight');

            $('.courseCohortDropdownItem').not('[data-course="' + $(this).attr('data-course') + '"]').removeClass('expanded');
            $('.courseCohortDropdownItem[data-course="' + $(this).attr('data-course') + '"]').toggleClass('expanded');
        });
    } );
    </script>

</header>



<div class="mobile-selection" id="mobile-courses-selection"></div>
<div class="mobile-selection" id="mobile-notifications-selection"></div>






    <!-- Scripts for Modals -->

<script type="text/javascript" charset="utf-8">
	var ListSubscribers = {
		openModal: function() {
			$('#list-subscribers-modal .modal-content').text('Loading list of subscribers...')
													   .load('?action=listSubscribers', {}, function() {
														$(window).trigger('resize');
													});

			$('#list-subscribers-modal').modal({
				show: true
			});
			
		},
		closeModal: function() {
			$('#list-subscribers-modal').modal('hide');
		}
	};

	var ListSubpages = {
		openModal: function() {
			$('#list-subpages-modal .modal-content').text('Loading list of sub-pages...')
													.load('?action=listSubpages', {}, function() {
														$(window).trigger('resize');
													});

			$('#list-subpages-modal').modal({
				show: true
			});
			
		},
		closeModal: function() {
			$('#list-subpages-modal').modal('hide');
		}
	};

	var AddSubpage = {
		currentPage: 'https://www.openlearning.com/unsw/courses/COMP1927-2013S2/FuryOfDracula/Files_v0.02/hunter.h/',
		pageToCreate: '',
		openModal: function() {
			$('#add-subpage-modal').modal({
				show: true
			});

			// Highlight the input box upon modal open -- cause clicking sucks
			$('#add-subpage-modal').on('shown', function() {
				$('#addSubpageName').focus()
			});
		},
		closeModal: function() {
			$('#add-subpage-modal').modal('hide');
		},

		// Context: the textbox
		updateUrlPreview: function() {
			var pageTitle = $(this).val();

			var capitalizedPageTitle = pageTitle.toLowerCase().replace(/\b([a-z])/gi,function( word ){ return word.toUpperCase() });

			var unspacedPageTitle = capitalizedPageTitle.replace(/[^A-Za-z0-9]+/g, '');

			AddSubpage.pageToCreate = AddSubpage.currentPage + unspacedPageTitle;
			$('#addSubpageDynamicURL').text( unspacedPageTitle );
		},
		addSubpage: function() {
			document.location.href = AddSubpage.pageToCreate + '?title=' + $('#addSubpageName').val();
		},
	};

	
	JS.require( '$.fn.modal', function() {
		$(document).ready( function() {
			// Define references to the modals and their buttons.
			var listSubscribersModal = $('#list-subscribers-modal');
			var listSubpagesModal = $('#list-subpages-modal');
			var addSubpageModal = $('#add-subpage-modal');
			var listSubscribersModalButton = $('#listSubscribers');
			var listSubpagesModalButton = $('#listSubpages');
			var addSubpageModalButton = $('#addSubpage');
			var addSubpageForm = $('#addSubpageForm');

			// Attach handlers to the buttons
			listSubscribersModal.find('.btn-danger, .close').click(ListSubscribers.closeModal);
			listSubscribersModalButton.click(ListSubscribers.openModal);

			listSubpagesModal.find('.btn-danger, .close').click(ListSubpages.closeModal);
			listSubpagesModalButton.click(ListSubpages.openModal);

			addSubpageModal.find('.btn-danger, .close').click(AddSubpage.closeModal);
			addSubpageModal.find('.btn-primary').click(AddSubpage.addSubpage);
			addSubpageModal.find('#addSubpageName').on('keyup', AddSubpage.updateUrlPreview);
			addSubpageForm.submit(function(e) { e.preventDefault(); AddSubpage.addSubpage(); });
			addSubpageModalButton.click(AddSubpage.openModal);

	
		} );
	} );
</script>

<!-- List Subscribers Modal -->
<div id="list-subscribers-modal" class="modal hide fade">
	<div class="modal-header">
		<a href="#" class="close">&times;</a>
		<h3>List of Subscribers</h3>
	</div>
	<div class="modal-body">
		<p class="modal-content">
			
		</p>
	</div>
	<div class="modal-footer">
		<a href="#" class="btn btn-inverse" data-dismiss="modal">Close</a>
	</div>
</div>

<!-- List Subpages Modal -->
<div id="list-subpages-modal" class="modal hide fade">
	<div class="modal-header">
		<a href="#" class="close">&times;</a>
		<h3>Pages under hunter.h</h3>
	</div>
	<div class="modal-body">
		<p class="modal-content">
			
		</p>
	</div>
	<div class="modal-footer">
		<a href="#" class="btn btn-inverse" data-dismiss="modal">Close</a>
	</div>
</div>

<!-- Add Subpage Modal -->
<div id="add-subpage-modal" class="modal hide fade">
	<div class="modal-header">
		<a href="#" class="close">&times;</a>
		<h3>Add Subpage</h3>
	</div>
	<div class="modal-body">
		<p class="modal-content">
			<form id="addSubpageForm">
				<label>Subpage Name</label>
				<input type="text" id="addSubpageName" name="addSubpageName">
				<br><br>
				<label>URL Preview</label>
				<div id="addSubpageURLPreview">https://www.openlearning.com/unsw/courses/COMP1927-2013S2/FuryOfDracula/Files_v0.02/hunter.h/<span id="addSubpageDynamicURL" style="color: #00a;"></span></div>
			</form>
		</p>
	</div>
	<div class="modal-footer">

		<a href="#" class="btn btn-inverse" data-dismiss="modal">Cancel</a>
		<a href="#" class="btn btn-primary">Add Sub-page</a>
	</div>
</div>

<!-- Revert Revision Modal -->
<div id="revert-page-modal" class="modal hide">
	<div class="modal-header">
		<a href="#" class="close">&times;</a>
		<h3>Revert Changes</h3>
	</div>
	<div class="modal-body">
		<p class="modal-content">
			This will set this old revision of the page as the latest revision. Do you wish to proceed?
		</p>
	</div>
	<div class="modal-footer">
		<a class="btn btn-primary">Proceed with revert</a>
		<a class="btn btn-danger">Cancel</a>
	</div>
</div>


<style>
	.macro-embedly {
		display: inline-block;
	}

	.macro-math {
		display: inline-block;
	}

	.macro-video {
		display: inline-block;
	}
</style>

<script type="text/javascript" src="https://www.openlearning.com/media-455534c/lib/audiojs/audio.min.js"></script>

<script type="text/javascript">
JS.require( 'jQuery', '$.fn.embedly', 'API', function( ) {
	$(document).ready( function( ) {
		$('.macro-embedly').each(function() {
			var url = $(this).data('url');
			var link = $('<a/>').attr('href', url).text(url);
			$(this).html(link);
			link.embedly({
				maxWidth: 700,
				secure: true,
				key:'fd7568db26dc465181ca1474f92bf0cc'
			});
		});

		$('.macro-math').each(function() {
			var latex = $(this).data('latex');
			var link = $('<img/>').attr('src', 'http://latex.codecogs.com/gif.latex?' + latex);
			$(this).html(link);
		});

		$('.macro-video').each(function() {
			var url = encodeURIComponent($(this).data('url'));
			var width = $(this).data('width');
			var $that = $(this);
			API.get('macro/video/', { 'width': width, 'videoUrl': url }).done(function(result) {
				$that.html(result.embedVideoHTML);
			}).fail(function() {
				$that.html($('<div/>').html('This video is not available.'));
			});
		});

		$('.macro-container').each(function() {
			var $container = $(this);
			var containerType = $container.data('type') || 'container-rounded';
			var $contents = $container.contents();

			var $newContents = $('<div/>').addClass(containerType).append($contents.clone());

			$contents.replaceWith($newContents);
		});

		$('.macro-audio').each(function() {
			var $audio = $(this);
			var url = $audio.data('url');
			if (!/^(f|ht)tps?:\/\//i.test(url)) {
				url = 'https://www.openlearning.com/' + $audio.data('url') + '?action=download';
			}

			var $audioElement = $('<div>').append($('<audio>').attr('src', url).attr('preload', 'none'));
			$audioElement.append($('<a/>').attr('href', url).text('Download this audio file.'));
			$audio.append($audioElement);
		});
		audiojs.events.ready(function() { var as = audiojs.createAll(); });

		$('.macro-subpages').each(function() {

			var $subpages = $(this);
			var path = $subpages.data('path');
			var sort = $subpages.data('sort');

			if (sort != null && sort.length > 0) {
				sort = '?sort=' + sort;
			} else {
				sort = '';
			}
			
			API.get('page/' + path + '/subpages' + sort, function() {

			}).done(function(res) {
				var $subpageTable = $('<table class="table table-hover table-condensed subpages-table"><thead><tr><th>Page</th><th class="last-update">Last Updated</th></tr></thead><tbody></tbody></table>');

				for (var i = 0; i < res.subpages.length; i++) {
					$subpageTable.append( 
						$('<tr/>').append(
							$('<td/>').append(
								$('<a/>').attr('href', res.subpages[i].url).text(res.subpages[i].title)
							), 
							$('<td/>').addClass('last-update').text(res.subpages[i].lastUpdate)
						)
					);
				}

				$subpages.append($subpageTable);
			});
		});

		var revealToggle = function( ) {
			var $spoiler = $(this).parents('.macro-spoiler');
			$spoiler.find('.spoiler-tag').toggleClass('spoiler-tag-displayed');
			$spoiler.find('.spoiler-reveal').toggle();
			$spoiler.find('.spoiler-content').slideToggle( "fast" );
			$spoiler.toggleClass('spoiler-displayed');
			$spoiler.find('.spoiler-tag-hide').toggle();
			return false;
		};

		$('.macro-spoiler').each(function() {
			var $spoiler = $(this);
			var title = $spoiler.data('title') || "Spoiler!";
			var $contents = $spoiler.contents();
			var $newContents = $(document.createDocumentFragment());

			$newContents.append($('<div class="spoiler-reveal"></div>').append($('<a href="#"><i>Click to Reveal</i></a>')).click(revealToggle));
			$newContents.append($('<div>').attr('class', 'spoiler-content').append($contents.clone()));
			$newContents.append($('<div>').attr('class', 'spoiler-tag').append(title).click(revealToggle));
			$newContents.append($('<div class="spoiler-tag-hide hide"><a href="#"><i class="icon-caret-up"></i></a></div>').click(revealToggle));

			if ($contents.length) {
				$contents.replaceWith($newContents);
			} else {
				$spoiler.append($newContents);
			}
		});
	});
});
</script>

<script type="text/javascript">
JS.require('PageMetricsOverlay', function() {
    var pageMetrics = new PageMetricsOverlay();
    $('#overlayPageMetrics').click(function() {
        if (pageMetrics.visible) {
            pageMetrics.hide();
        } else {
            pageMetrics.load();
        }
        return false;
    });
});
</script>
<script type="text/javascript">
JS.require( 'jQuery', '$.fn.embedly', function( ) {
    $(document).ready( function( ) {
        $('.embedLink').each(function() {
            $(this).embedly({
                maxWidth: 700,
                secure: true,
                key:'fd7568db26dc465181ca1474f92bf0cc'
            });
        });
    });
});
</script>



<section class="page-section first-page-section">
	<div class="container page-container first-page-container">
		<div class="row">
			<div class="span12">
				<div style="position: relative; height: 100px; ">
					<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2">
						<div id="course-banner-link" style="cursor: pointer; width: 100%; position: absolute;">
							<div id="course-banner">
								<div id="course-live-ribbon" class="ribbon-wrapper-blue hide">
									<div class="ribbon-blue">
										<span id="offline-banner" title="Course is not yet visible to students. Click here to change course settings.">Offline</span>
									</div>
								</div>
							
								<h1 class="banner-title">Computing 2</h1>
							
							</div>
						</div>
					</a>
					
					<a href="https://www.openlearning.com/unsw">
						<div style="position: absolute; right: 0; width:300px; height: 100px; display:block"></div>
					</a>
					
				</div>
			</div>
		</div>
	</div>
</section>
<section class="page-section">
	<div class="container page-container last-page-container">
		<div class="row course-container-row">
	
			<div class="span2 blogwidgetarea courseSidebar">
				
				<ul id="course-links">
				
					
					<li class="cat-item wrappable-link">
						<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2">
							Announcements
						</a>
					</li>
					
					<li class="cat-item wrappable-link">
						<a href="http://www.cse.unsw.edu.au/~cs1927/13s2/CourseOutline.html" target="_blank">
							Course Outline
						</a>
					</li>
					
					<li class="cat-item wrappable-link">
						<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/Schedule">
							Lectures &amp; Activities
						</a>
					</li>
					
					<li class="cat-item wrappable-link active">
						<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/FuryOfDracula">
							Fury Of Dracula
						</a>
					</li>
					
					<li class="cat-item wrappable-link">
						<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/Resources">
							Resources
						</a>
					</li>
					
					<li class="cat-item wrappable-link">
						<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort">
							Discussions &amp; Groups
						</a>
					</li>
					
					<li class="cat-item wrappable-link">
						<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/WhenAndWhere">
							When &amp; Where
						</a>
					</li>
					
					<li class="cat-item wrappable-link">
						<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/CourseFeed">
							Feed
						</a>
					</li>
					
					<li class="cat-item wrappable-link">
						<a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/TutorArea">
							Tutor Area
						</a>
					</li>
					
				

				

				
				</ul>
				
				
	

	<script type="text/javascript" charset="utf-8">
		JS.require('jQuery','dust','API', function() {
			$.getScript('https://www.openlearning.com/media-455534c/lib/dust/compiled_templates/page.dust').done(function() {
				API.get('page/relatedTo/unsw/courses/COMP1927-2013S2/FuryOfDracula/Files_v0.02/hunter.h').done(function( res ) {
					$(res.relatedPages).each(function(key, value) {
						dust.render("relatedContent", value, function(err, out) {
							$('#related-pages').prepend($(out));
						});
					});
                    var relatedContentTitle = $('#relatedContentTitle').detach();
                    $('#related-pages').prepend(relatedContentTitle);
				});
			});
			$(document).ready(function() {
				$('#relatedContentForm').submit(function(e) {
					e.preventDefault();

					var pageTitle = $(this).find('input[name=title]').val();

					// upper case every word
					var capitalizedPageTitle = pageTitle.toLowerCase().replace(/\b([a-z])/gi,function( word ){ return word.toUpperCase() });

					var unspacedPageTitle = capitalizedPageTitle.replace(/[^A-Za-z0-9]+/g, '');

					$(this).find('input[name=title]').val(capitalizedPageTitle);

					
					var prefix = 'https://www.openlearning.com/unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort/Pages/';
					

					$(this).attr('action', prefix + unspacedPageTitle);
					if (capitalizedPageTitle.length > 0) {
						$(this).off("submit");
						$(this).submit();
					}
				});
			});	
		});	
	</script>
	<ul id="related-pages">
        <li style="text-align:center" id="relatedContentTitle">
        <a href="."><h5 style="margin:0">Related Content</h5></a>
        </li>
		<li style="padding: 10px;"><form id="relatedContentForm" method="get" class="form-inline">
		<div class="input-append">
		  <input type="hidden" name="relatedToPage" value="unsw/courses/COMP1927-2013S2/FuryOfDracula/Files_v0.02/hunter.h">
		  <input class="relatedContentTitle" name="title" size="16" type="text" placeholder="Create content..."><button class="btn" type="submit">Go</button>
		</div>
	</form></li>
	</ul>

	

				
			</div>
			<div class="span10 no-pad-top course-page-container">
	
		

<div id="course-info-placeholder"></div>
<div id="course-info">
	<div class="course-stats">
		
		<span class="pull-left" style="margin-right: 5px;">
			<a href="https://www.openlearning.com/u/lucas.pickup" class="profile-link" title="Lookin' good :)">
				<img src="https://openlearning-cdn.s3.amazonaws.com/lucas.pickup-avatar-48-ts1375065579.jpg" border="0" style="width:35px;height:35px;">
			</a>
		</span>
		

		
		<div id="user-karma" class="pull-left" title="<strong>Your Karma</strong><br>0 content + 3 comment">
			<a href="#">
				<span>3</span>
			</a>
		</div>
		

		

		
		
		<div id="progress-container" class="pull-right">
			<div class="progress pull-left">
				<div id="progress-bar-completed" class="progress-bar bar-success" data-status="completed" style="width: 34.78260869565217391304347826%;" title="8 completed"><span id="progress-complete-message" class="hide">
						You are Awesome!
					</span></div><div id="progress-bar-pending" class="progress-bar bar-info" data-status="pending" style="width: 30.43478260869565217391304348%;" title="7 pending">&nbsp;</div><div id="progress-bar-remaining" class="progress-bar bar-nothing" data-status="incomplete" style="text-align: center; width: 34.78260869565217391304347826%;" title="8 not yet completed"><span id="progress-empty-message" class="hide">Start an Activity</span></div>
			</div>

			<div class="pull-left">
				<!--ul id="progress-text-summary">
					<li class="progress-text" data-status="incomplete">
						<span id="progress-unstarted">3</span> <span id="unstarted-label"> unstarted activities</span>
					</li>
					<li class="progress-text hide" data-status="incomplete">
						<span id="progress-started">0</span> <span id="started-label"> started activities</span>
					</li>
					
					<li class="progress-text" data-status="overdue">
						<span id="progress-overdue">5</span> <span id="overdue-label"> overdue activities</span>
					</li>
					
				</ul-->
			</div>
		</div>
		
		
		<div id="progress-badge-container">
			<ul id="sidebar-badges" class="hide"></ul>
			<ul id="sidebar-optional-activity-badges" class="hide"></ul>
		</div>
		
		<div class="clearfix"></div>
		
		<script type="text/javascript" charset="utf-8">
			JS.require('API', 'jQuery', '$.fn.tooltip', function (API, $) {

				var tooltipOptions = {
					placement: 'bottom',
					html: true,
					delay: { show: 200, hide: 200 }
				};

				var tooltipOptionsNoHTML = {
					placement: 'bottom',
					delay: { show: 200, hide: 200 }
				}

				// Retrieve badges
				API.get('badges/lucas.pickup?cohort=unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort').done(function(res) {
					var $sidebarBadges = $('#sidebar-badges');
					$.each(res.badges, function(k,v) {
						var $badgeImage = $('<img/>').attr('src', v.image);
						var $badgeLink = $('<a/>').attr({
														'href': v.url,
												}).append( $badgeImage );
						var $badge = $('<li/>').attr('title', v.name).append( $badgeLink ).tooltip(tooltipOptionsNoHTML);
						$sidebarBadges.append( $badge );
					});
					$sidebarBadges.show();
				});

				// Retrieve completed option activity icons
				API.get('getUserCompletedOptionalActivities/unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort').done(function(res) {
					if (res.completedActivities.length > 0) {
						var $optionalBadges = $('#sidebar-optional-activity-badges');
						$.each(res.completedActivities, function(k,v) {
							var $badgeImage = $('<img/>').attr('src', v.activityIcon);
							var $badgeLink = $('<a/>').attr({
														'href': v.activityURL
													}).append( $badgeImage );
							var $badge = $('<li/>').attr('title', v.activityName).append( $badgeLink ).tooltip(tooltipOptionsNoHTML);
							$optionalBadges.append( $badge );
						});
						$optionalBadges.show();
					}
				});

				$(document).ready(function() {
					// Make the bar follow you
					var headerBarHeight = 35;
					var topColorBarHeight = 0;
					var bottomColorBarHeight = 1;

					var $footer = $('footer');
					var $courseInfo = $('#course-info');
					var $courseInfoPlaceholder = $('#course-info-placeholder');
					var initialCourseInfoTop = $courseInfo.offset().top;
					var $window = $(window);
					var $coursePageContainer = $('.course-page-container');

					$window.on('scroll resize', function() {
						var isMobileWidth = $window.width() < 780;
						if (isMobileWidth) {
							$courseInfoPlaceholder.hide();
							$courseInfo.removeClass('fixed-course-info').removeClass('absolute-course-info').css({'width': 'inherit'});
							return;
						}

						// footer top needs to be recalculated because of dynamic comment loading
						var footerTop = $footer.offset().top; 
						var courseInfoHeightWithMargin = $courseInfo.outerHeight(true);
						if ($courseInfo.hasClass('absolute-course-info')) {
							courseInfoHeightWithMargin = courseInfoHeightWithMargin - topColorBarHeight + bottomColorBarHeight;
						}
						var containerWidth = $coursePageContainer.width();
						var scrollTop = $window.scrollTop();

						if (scrollTop > footerTop - courseInfoHeightWithMargin - headerBarHeight) {
							$courseInfo.addClass('absolute-course-info').removeClass('fixed-course-info').css({'width': 'inherit'});
						} else if (scrollTop > initialCourseInfoTop - headerBarHeight + topColorBarHeight) {
							$courseInfoPlaceholder.show();
							$courseInfo.removeClass('absolute-course-info').addClass('fixed-course-info').css({'width': containerWidth + 'px'});
						} else {
							$courseInfoPlaceholder.hide();
							$courseInfo.removeClass('fixed-course-info').removeClass('absolute-course-info').css({'width': 'inherit'});
						}
					});

					$('#user-karma[title], .progress .progress-bar[title]').tooltip(tooltipOptions);

					$('.progress-bar, .progress-text').click(function() {
						var status = $(this).attr('data-status');
						window.location = 'https://www.openlearning.com/progress/?course=unsw/courses/COMP1927-2013S2#' + status;
					});

					$('.profile-link').tooltip(tooltipOptionsNoHTML);


					var $userKarma = $('#user-karma');
					window.updateKarma = function() {
						API.get('getUserCohortInfo/unsw/courses/COMP1927-2013S2/Cohorts/FirstCohort/lucas.pickup').done(function(data) {
							var karma = data.karma;
							if (karma) {
								var $contents = $userKarma.contents();
								var $newContents = $contents.clone();
								var newTitle = karma.page + ' content + ' + karma.comment + ' comment';
								$newContents.filter('a').tooltip('destroy').attr('title', newTitle).tooltip(tooltipOptions);
								$newContents.find('span').contents().replaceWith(karma.total + ' karma');
								$contents.replaceWith($newContents);
							}
						});
					};

					var $emptyMessage = $('#progress-empty-message');
					var $completeMessage = $('#progress-complete-message');
					window.updateProgress = function() {
						var updateURL = 'https://www.openlearning.com/progress/?course=unsw/courses/COMP1927-2013S2&format=json';

						$.ajax( updateURL, {
							type: 'GET',

							success: function(data) {
								progress = data.progressData;

								$emptyMessage.hide();
								$completeMessage.hide();

								var taskMap = {
									'remaining': 'incomplete'
								};

								var textMap = {
									'remaining': 'not yet completed'
								};

								$.each(['completed', 'pending', 'remaining'], function(i, state) {
									var titledState = state[0].toUpperCase() + state.slice(1);
									var percentage = progress['percentage' + titledState];
									var taskState = taskMap.hasOwnProperty(state) ? taskMap[state] : state;
									var numTasks = progress[taskState + 'Tasks'];
									var verb = textMap.hasOwnProperty(state) ? textMap[state] : state;
									$('#progress-bar-' + state).css('width', percentage + '%').attr('title', numTasks + ' ' + verb);
								});

								// refresh tooltips
								$('#user-karma[title], .progress .progress-bar[title]')
									.tooltip( 'destroy' )
									.tooltip(tooltipOptions);

								// show relevant messages
								if (progress.percentageCompleted === 100) {
									$completeMessage.show();
								} else if (progress.percentageRemaining === 100) {
									$emptyMessage.show();
								}

								var $textSummary = $('#progress-text-summary').contents();
								var $newTextSummary = $textSummary.clone();
								var progressStates = ['unstarted', 'started', 'overdue'];

								// hide all states and only show non-zero ones
								$newTextSummary.find('li').hide();
								$.each(progressStates, function(i, state) {
									var numTasks = progress[state + 'Tasks'];
									if (numTasks > 0) {
										var plural = (numTasks == 1) ? 'y' : 'ies';
										var $progress = $newTextSummary.find('#progress-' + state);
										$progress.contents().replaceWith(document.createTextNode(numTasks));
										$newTextSummary.find('#' + state + '-label').contents().replaceWith(state + ' activit'  + plural);
										$progress.closest('li').show();
									}
								});
								$textSummary.replaceWith($newTextSummary);
							},
							error: function() {
							}
						} );
					};
				});
			});
		</script>
		
	</div>
</div>


	
	
				<div id="course-page-content">
	
                <div id="page-options">
        
                    <div class="page-options-edit">
                        
                        
                        <div class="page-options-caret btn-group">
                            <a class="dropdown-toggle" data-toggle="dropdown" href="#">
                                <i class="icon icon-caret-down"></i>
                            </a>
                            <ul class="dropdown-menu dropdown-right edit-menu">
                            
                                <li>
                                    <a href="?action=history">
                                        <i class="icon-time"></i> Page History
                                    </a>
                                </li>
                            
                                <li>
                                    <a id="listSubpages" href="#">
                                        <i class="icon-list-ul"></i> View Sub-pages
                                    </a>
                                </li>
                            
                            </ul>
                        </div>
                        
                    </div>
                    

            
                
                    
                    <div id="subscription-button" class="page-options-subscribe">
                        <i class="icon icon-globe"></i> Subscribe<span class="subscribedTense">d</span>
                    </div>
                    
                
            
        
                </div>
        

        
                <span class="breadcrumbs">
            
                
                
                    
                    
                        <a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/FuryOfDracula">FuryOfDracula</a> &raquo;
                    
                    
                
                    
                    
                        <a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/FuryOfDracula/Files_v0.02">Files_v0.02</a>
                    
                    
                
            
                </span>
        

        
                <div id="page-header-container">
            
                
            
                    <h1 class="title">
            
                
                    
                        <a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/FuryOfDracula/Files_v0.02/hunter.h">
                            <span>hunter.h</span>
                        </a>
                        <span class="sub-title"></span>
                    
                
            
                    </h1>
                </div>
        
    
	
    

	

	
	<pre class="prettyprint linenums">// hunter.h
// Interface to your Fury of Dracula hunter AI
// By: TeamDracula
// Date: 1 January 2012
// Version: 1.0

void decideMove (HunterView gameState);</pre>


	
	

<p>	
	<div style="margin-top: 10px;">
		Download file: <a href="https://www.openlearning.com/unsw/courses/COMP1927-2013S2/FuryOfDracula/Files_v0.02/hunter.h?action=download"><img src="https://www.openlearning.com/media-455534c/images/icons/16x16/attach.png" align="absmiddle"> hunter.h</a>
		(158 bytes)
	</div>
</p>






    


	<div class="page-content">
	

	</div>
	

    
	
<div id="pageFooter">
    <div id="page-footer-tag-list">
        <div style="margin-top: 4px;">
	
	
	
</div>

    </div>

    <div id="page-footer-last-modified">
        
<div class="pageLastUpdateInfo" style="margin-top: 2px;">
	
	<img src="https://openlearning-cdn.s3.amazonaws.com/damon.stacey-avatar-48-ts1342438109.jpg" align="absmiddle">
	
	<a href="https://www.openlearning.com/u/damon.stacey">Damon Stacey</a>
	 &ndash; edited <span class="last-edited-timestamp" title="2013-09-23T08:24:46.165Z">Mon, Sep 23 2013 6:24 p.m.</span>
	 &ndash; <a href="?action=history">history</a>
</div>
<script type="text/javascript">
JS.require('jQuery.timeago', '$.fn.tooltip', function() {
	$(function() {
		$('.last-edited-timestamp').timeago().tooltip();
	});
});
</script>

    </div>
    <br clear="all">
</div>

				</div>
	
	

<div id="communityFooter">
    <div id="page-footer-community"></div>
    <div id="community-heading-container">
	<a name="comments"></a>
	<div id="community-heading-left">
		<div id="community-heading-title">
			<h4>
				<i class="icon icon-comments"></i>
				
				Comments
				
			</h4>
		</div>
	</div>

	<div id="community-heading-right"></div>


	<div style="clear: both;">
		<!-- so that floats don't overlap -->
	</div>
</div>
<div class="comments" id="comments-container-main" data-placeholderText="" data-document="523ffacdb919662b177a576f" data-collapsed="0" data-subscription="" data-sorting="time" data-canComment="1" data-disablecommenting="0" data-pinboardEnabled="0">
	<noscript>Comments can only be displayed in a JavaScript enabled browser. Please enable JavaScript and try again.</noscript>
</div>
<script type="text/javascript">
document.getElementById('comments-container-main').innerHTML = "Comments loading...";
</script>

<style type="text/css">
	.subtle-button-group {
		opacity: 0.5;
		-moz-opacity: 0.5;
		filter:alpha(opacity=50);
	}

	.subtle-button-group:hover {
		opacity: 1.0;
		-moz-opacity: 1.0;
		filter:alpha(opacity=100);
	}
</style>

<script type="text/javascript" charset="utf-8">
	
	JS.require('Commenting', function() {
		var $commentsContainer = $('#comments-container-main');

		new Commenting($commentsContainer, {
			notifications: ''
		});
		
		var collapsed = $commentsContainer.attr('data-collapsed') === '1';
		var sorting = $commentsContainer.attr('data-sorting');
		var sortingMap = {
			'time': "New Threads",
			'likes': "Top Rated",
			'bump': "Recent Replies",
			'replies': "Most Replies"
		};

		if (!sortingMap.hasOwnProperty(sorting)) {
			sorting = 'time';
		}

		var $communityHeading = $('#community-heading-right');

		$.ajaxSetup({'cache': true});
		$.getScript(baseMedia + 'lib/dust/compiled_templates/comments.dust').done(function() {
			var templateData = {
				'collapsed': collapsed,
				'sortKey': sorting,
				'sortText': sortingMap[sorting],
				'sorts': $.map(sortingMap, function(value, key) {
					return {
						'key': key,
						'text': value
					};
				})
			};

			function toggleComments(e) {
				e.preventDefault();
				$commentsContainer.find(templateData.collapsed ? '.expandButton' : '.collapseButton').click();
				templateData.collapsed = !templateData.collapsed;
				dust.render('heading', templateData, function(err, html) {
					$communityHeading.contents().replaceWith($(html).filter('#toggle-comments').click(toggleComments).end());
				});
			};

			dust.render('heading', templateData, function(err, html) {
				$(html).filter('#toggle-comments').click(toggleComments).end().appendTo($communityHeading);
			});
		});
	});
</script>

</div>


			</div>
		</div>
	</div>
</section>


<script type="text/javascript">
JS.require('jQuery', function() {
	$('#course-admin-link a.admin-access-menu').click(function(e) {
		var $this = $(this);
		$this.find('i').toggleClass('icon-caret-right icon-caret-down');
		$this.next('ul').slideToggle(function() {
			sessionStorage && sessionStorage.setItem("ol-course-nav-open", '' + $this.next('ul').is(':visible'));
		});
		return false;
	});
	$('#teacher-admin-link a.teacher-access-menu').click(function(e) {
		var $this = $(this);
		$this.find('i').toggleClass('icon-caret-right icon-caret-down');
		$this.next('ul').slideToggle(function() {
			sessionStorage && sessionStorage.setItem("ol-teacher-nav-open", '' + $this.next('ul').is(':visible'));
		});
		return false;
	});
    var $this = $('#course-admin-link a.admin-access-menu');
    if ((sessionStorage && sessionStorage.getItem("ol-course-nav-open") == 'true') || false) {
        $this.find('i').removeClass('icon-caret-right');
        $this.find('i').addClass('icon-caret-down');
        $this.next('ul').show();
    } else {
        $this.find('i').removeClass('icon-caret-down');
        $this.find('i').addClass('icon-caret-right');
        $this.next('ul').hide();
    }
    $this = $('#teacher-admin-link a.teacher-access-menu');
    if ((sessionStorage && sessionStorage.getItem("ol-teacher-nav-open") == 'true') || false) {
        $this.find('i').removeClass('icon-caret-right');
        $this.find('i').addClass('icon-caret-down');
        $this.next('ul').show();
    } else {
        $this.find('i').removeClass('icon-caret-down');
        $this.find('i').addClass('icon-caret-right');
        $this.next('ul').hide();
    }

    $('#offline-banner').click(function(e) {
        e.preventDefault();
        window.location.href = "https://www.openlearning.com/courses/admin/?course=unsw/courses/COMP1927-2013S2&action=general";
    });
});
</script>



    
        
        <footer class="footer">
            <!-- Widget Area -->
            <section class="footerwidgetarea">
                <div class="container">
                    <div class="row">

                        <div id="information-widget" class="span4 footerwidget">
                            <h3 class="text-center inverse-font">Information</h3>
                            <div class="row">
                                <div class="span2">
                                    <ul>
                                        <li>
                                            <span class="footer-header">Company</span>
                                        </li>
                                        <li>
                                            <a href="https://www.openlearning.com/blog">Blog</a>
                                        </li>
                                        <li>
                                            <a href="https://www.openlearning.com/About">About Us</a>
                                        </li>
                                        <li>
                                            <a href="https://www.openlearning.com/help">
                                                Help &amp; Support
                                            </a>
                                        </li>
                                        <li>
                                            <a href="https://www.openlearning.com/press">
                                                Press
                                            </a>
                                        </li>
                                        <li>
                                            <a href="mailto:support@openlearning.com?subject=I have a question about openlearning...">Contact</a>
                                        </li>
                                    </ul>
                                </div>
                                <div class="span2">
                                    <ul>
                                        <li>
                                            <span class="footer-header">Education</span>
                                        </li>
                                        <li>
                                            <a href="https://www.openlearning.com/courses/">
                                                All courses
                                            </a>
                                        </li>
                                        <li>
                                            <a href="https://www.openlearning.com/courses/create/">
                                                Create a course
                                            </a>
                                        </li>
                                        <li>
                                            <a href="https://www.openlearning.com/jobs">
                                                Jobs
                                            </a>
                                        </li>
                                        <li>
                                            <a href="https://www.openlearning.com/thankyou">
                                                Thank you
                                            </a>
                                        </li>
                                    </ul>
                                </div>
                            </div>
                            <h4 id="subscription-header" class="text-center inverse-font">Do you love learning?</h4>
                            <p class="text-center footer-p">
                                Subscribe to our newsletter about online learning and using OpenLearning
                            </p>
                            <form method="post" action="https://openlearningcom.createsend.com/t/i/s/aykr/" id="subscribe-form" class="text-center">
                                <input name="cm-aykr-aykr" id="aykr-aykr" type="text" placeholder="Email address..." style="margin-bottom: 0px;">
                                <input type="submit" class="btn btn-success" value="Subscribe &raquo;">
                            </form>
                        </div>

                        <div class="span4 footerwidget latest-blog-posts-footerwidget">
                            <h3 class="text-center inverse-font">Latest Blog Posts</h3>
                            <ul class="footerblog_post">
        
                                <li>
                                    <span class="blogpost-music">
                                        <i class="icon-music"></i>
                                    </span>
                                    <p>
                                        <a href="https://www.openlearning.com/blog" title="Blog Post" class="inverse-link">
                                            24 Sep 2013 - Read More &rarr;
                                        </a>
                                    </p>
                                    <p><strong>Teach Amazing Courses</strong> 



&quot;I&#39;m in love with the new look ;) Thank you!&quot; - Loveleen...</p>
                                </li>
        
                                <li>
                                    <span class="blogpost-music">
                                        <i class="icon-music"></i>
                                    </span>
                                    <p>
                                        <a href="https://www.openlearning.com/blog" title="Blog Post" class="inverse-link">
                                            26 Jul 2013 - Read More &rarr;
                                        </a>
                                    </p>
                                    <p><strong>Student Champions</strong> We&#39;re really excited to launch our Student Champion program!...</p>
                                </li>
        
                                <li>
                                    <span class="blogpost-music">
                                        <i class="icon-music"></i>
                                    </span>
                                    <p>
                                        <a href="https://www.openlearning.com/blog" title="Blog Post" class="inverse-link">
                                            17 Jun 2013 - Read More &rarr;
                                        </a>
                                    </p>
                                    <p><strong>Richard Buckland named NSW Educator of the Year</strong> [image]A huge congratulations to Richard Buckland on his lat...</p>
                                </li>
        
                            </ul>
                        </div>
                        <div class="span4 footerwidget text-center social-media-footerwidget">
                            <h3 class="text-center inverse-font">Social Media</h3>
                            <div id="social-buttons-container">
                                <div class="row">
                                    <div class="span2">
                                        <a href="https://twitter.com/openlrning" class="twitter-follow-button" data-show-count="false" data-dnt="true">Follow @openlrning</a>
                                        <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
                                    </div>
                                    <div class="span2">
                                        <iframe src="//www.facebook.com/plugins/like.php?href=http%3A%2F%2Fwww.facebook.com%2Fpages%2FOpenLearning%2F347961805277601&amp;send=false&amp;layout=button_count&amp;width=100&amp;show_faces=false&amp;action=like&amp;colorscheme=light&amp;font&amp;height=21&amp;appId=203356799790933" scrolling="no" frameborder="0" style="border:none; overflow:hidden; width:100px; height:21px;" allowTransparency="true"></iframe>
                                    </div>
                                </div>
                            </div>
                            <div id="technology-badges-container">
                                <a id="rackspace-badge" href="http://rackspace.com/" target="_blank">
                                    <img src="https://www.openlearning.com/media-455534c/images/redesign/footer-rackspace.png" border="0" alt="Powered by Rackspace Hosting">
                                </a>

                                <a id="mixpanel-badge" href="https://mixpanel.com/f/partner">
                                    <img src="//cdn.mxpnl.com/site_media/images/partner/badge_light.png" alt="Mobile Analytics" />
                                </a>
                                <div class="clearfix"></div>
                            </div>

                            <div class="pad50 padbottom30">
                                <a href="https://www.openlearning.com/">
                                    <img src="https://www.openlearning.com/media-455534c/images/redesign/footer-logo.png" border="0" alt="OpenLearning">
                                </a>
                            </div>
                        </div>
                    </div>
                </div>
            </section>
            <!-- Widget Area -->
            <div class="container">
                <!-- Copyright & Social Area -->
                <div class="row">
                    <div class="span12 text-center copyright">
                        <p>&copy;2013 Open Learning Global Pty Ltd. Use subject to our <a href="https://www.openlearning.com/PrivacyPolicy">Privacy Policy</a> and <a href="https://www.openlearning.com/TermsOfService">Terms of Service</a>.</p>
                    </div>
                    <div class="span12 text-center footersocial">
                       <p>
                           <a href="https://facebook.com/OpenLearning" title="Follow us on Facebook" class="inverse-link"><i class="icon-facebook"></i></a>
                           <a href="https://twitter.com/openlrning" title="Follow us on Twitter" class="inverse-link"><i class="icon-twitter"></i></a>
                           <a href="https://youtube.com/user/openlearningcom" title="Follow us on YouTube" class="inverse-link"><i class="icon-youtube"></i></a>
                           <a href="http://au.linkedin.com/company/open-learning" title="Follow us on Linked In" class="inverse-link"><i class="icon-linkedin"></i></a>
                       </p>
                    </div>
                </div>
                <!-- Copyright & Social Area -->
            </div>
        </footer>
        
    

  

<script>

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-27113294-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>



    

<link rel="stylesheet" type="text/css" href="https://www.openlearning.com/media-455534c/new/css/pages/courseChat.css">

<div class="course-chat-listing shrunk">
    <div class="course-chat-toolbar">
        <span id="course-chat-online-text">Online</span><span class="badge badge-success" id="course-chat-num-online"><i class="icon-ellipsis-horizontal" style="color: white"></i></span>
        <span class="pull-right chat-chevrons">
            <i class="icon-chevron-up"></i>
            <i class="icon-chevron-down"></i>
        </span>
    </div>
    <div class="course-chat-header">
        <div class="pull-right">
            <span>Chat:</span>
            <div class="btn-group online-offline-buttons" data-toggle="buttons-radio">
                <button type="button" class="btn btn-mini btn-success online-offline-button" id="chat-online-button">On</button>
                <button type="button" class="btn btn-mini online-offline-button" id="chat-offline-button">Off</button>
            </div>
        </div>
        <a href="https://www.openlearning.com/accounts/conversations/">Chat History</a>
        <div class="clearfix"></div>
    </div>
    <div class="course-chat-list-container">
        <ul class="course-chat-list-online">
            <li class="course-chat-loading-placeholder">loading ...</li>
        </ul>
    </div>

    <!-- TODO: these go into dust template -->
    <ul class="hide">
        <li class="pm-chat-message-item" id="pm-template">
            <img class="pm-chat-avatar">
            <div class="pm-chat-message-thread">
            </div>
            <div class="pm-chat-message-time">
            </div>
        </li>
    </ul>
    <ul class="hide">
        <li class="pm-chat-box" id="pm-box-template">
            <div class="pm-chat-box-header">
                <div class="pm-chat-title"></div>
                <div class="pm-chat-pending"></div>
                <div class="pm-chat-close">&times;</div>
            </div>
            <div class="pm-chat-box-content">
                <ul class="pm-chat-messages">
                </ul>
                <textarea class="pm-chat-reply"></textarea>
            </div>
        </li>
    </ul>
    <ul class="hide">
        <li class="course-chat-user" id="course-chat-user-template">
            <img class="course-chat-avatar">
            <div class="course-chat-name">Name</div>
            <div class="course-chat-online-icon">
                <i class="icon-circle"></i>
            </div>
        </li>
    </ul>
    <!-- end makeshift templating -->
</div>

<div class="pm-chat-bar">
    <ul class="pm-chat-boxes">
    </ul>
</div>

<script src="https://d3dy5gmtp8yhk7.cloudfront.net/2.1/pusher.min.js" type="text/javascript"></script>
<script type="text/javascript">
    JS.require('UIChat', function() {
        var mediaURL = "https://www.openlearning.com/media-455534c/";
        var csrfToken = Utilities.getCookie('csrftoken');
        var isEncrypted = !false;
        var constants = {
            'emoticonURL': mediaURL + 'images/emoticons/',
            'emoticons': Emoticons(),
            'pusher_key': "c403c638058b566b52d8",
            'myProfileName': "lucas.pickup",
            'myAvatar': "https://openlearning-cdn.s3.amazonaws.com/lucas.pickup-avatar-48-ts1375065579.jpg",
            'chatStatus': "online",
            'pusherOptions': { 
                'authEndpoint': '/api/chat/auth/',
                'auth': {
                    'headers': {
                        'X-CSRF-Token': csrfToken
                    },
                    'params': {
                        'csrfmiddlewaretoken': csrfToken
                    }
                },
                'encrypted': isEncrypted
            }
        };

        var uiChat = new UIChat(constants);
        uiChat.run();
    });
</script>




<script src="https://www.openlearning.com/media-455534c/new/js/custom.js"></script>
<script type="text/javascript">
JS.require('jQuery', function() {
    var HEADER_BAR_HEIGHT = 35;
    var $window = $(window);
    var $coursesDropdownMenu = $('#courses-dropdown');
    function resizeCoursesMenu() {
        $coursesDropdownMenu.css('max-height', $window.height() - HEADER_BAR_HEIGHT - 20); // arbitrary padding from bottom
    }

    $(window).on('resize', resizeCoursesMenu);
    resizeCoursesMenu();
});
</script>
</div>
</body>
</html>
