$j=jQuery;

var larvaunched=false;
window.fbAsyncInit = function(){arevicotest};
function arevicotest(){

	if ( ( typeof(lb_l_ret.mobile)!='undefined' && lb_l_ret.mobile==1 ) //detect mobiles
		&& ((screen.width < 500) || (screen.height < 500) 
		|| /iphone|ipad|ipod|android|blackberry|mini|windows\sce|palm/i.test(navigator.userAgent.toLowerCase())	
		
		)){
		
	} else {
		arinitcode();
	}
};


function arinitcode() {
	if ((!larvaunched) && typeof(FB)!= 'undefined'){
    FB.init({
	    appId: lb_l_ret.appid,xfbml: true,    
	    status : true, // check login status
    	cookie : true, // enable cookies to allow the server to access the session
    });
    larvaunched=true;

    FB.Event.subscribe('edge.create', function(response) {

    if (lb_l_ret.gaevent==1 && (typeof(_gaq)!= 'undefined')) {
	    _gaq.push(['_trackSocial', 'facebook', 'like', response]);
    }
	if (lb_l_ret.hideonlike==1) {
	$j.fancybox.close();
	createCookie("arevico_lb_ns", "1", 90000);
	}

    });
	
	if (((lb_l_ret.show_once>0 && readCookie("arevico_lb")==1) ||  readCookie('arevico_lb_ns')==1)) 
	{
	
	
	} else {
		FB.getLoginStatus(function(response) {
	  	if (response.status === 'connected' ) {
   		var uid = response.authResponse.userID;
    	var accessToken = response.authResponse.accessToken;
    	FB.api('/'+ uid +'/likes/' + lb_l_ret.fb_id,function(response) {
   	
   	 if( response.data ) {
        if( !arv__isEmpty(response.data) ) {
         //   alert('You are a fan!');
         	createCookie("arevico_lb_ns", "1", 90000);
        } else {
           window.setTimeout(show_facebox, lb_l_ret.delay);
       }
   		 } else {
              window.setTimeout(show_facebox, lb_l_ret.delay);
		    }
		});
    
  		} else if (response.status === 'not_authorized'){

			window.setTimeout(show_facebox, lb_l_ret.delay); //loggedin

		 } else if (typeof(lb_l_ret.loggedin)!='undefined' && lb_l_ret.loggedin==1){ //not loggedin && only 
    		//not loggedin
	  } else {
 			 	window.setTimeout(show_facebox, lb_l_ret.delay);
	  }
	});

	}
		
	}
}
$j(document).ready(function(){

	/** lb_l_ret */
		if ((lb_l_ret.show_once>0 && readCookie("arevico_lb")==1) ||  readCookie('arevico_lb_ns')==1)
	{

	} else {
	var fb_locale='';
	if (lb_l_ret.fblocale==''){fb_locale='en_US';}else{fb_locale=lb_l_ret.fblocale}

	$j('body').append('<div id="fb-root"></div>');
	$j('body').append(construct_code());
	$j.getScript('//connect.facebook.net/' + fb_locale + '/all.js#xfbml=1&appId=' + 
		lb_l_ret.appid + "&status=1&cookie=1",function(script, textStatus, jqXHR){window.setTimeout(arevicotest, 200);});

	}

});

function show_facebox(){
	if (lb_l_ret.show_once>0){
		createCookie("arevico_lb", "1", lb_l_ret.show_once);
	}

//$j('iframe').css('overflow:hidden;');
$j('a#inline').fancybox({
	'modal': false,
	'padding' : 0,
	'scrolling' : 'no',
	'showCloseButton' : true,
	'autoDimensions':true,
	'width' : 'auto',
	'overlayOpacity':lb_l_ret.overlayop,
	'overlayColor':lb_l_ret.overlaycolor,
	'height': lb_l_ret.height,
	'centerOnScroll':true,
	'hideOnOverlayClick' : false
	}).trigger('click');
}

function createCookie(name,value,days) {
	if (days) {
		var date = new Date();
		date.setTime(date.getTime()+(days*24*60*60*1000));
		var expires = "; expires="+date.toGMTString();
	}
	else var expires = "";
	document.cookie = name+"="+value+expires+"; path=/";
}

function readCookie(name) {
	var nameEQ = name + "=";
	var ca = document.cookie.split(';');
	for(var i=0;i < ca.length;i++) {
		var c = ca[i];
		while (c.charAt(0)==' ') c = c.substring(1,c.length);
		if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
	}
	return null;
}


function construct_code(){
var fanpagestring='profile-id="' + lb_l_ret.fb_id +'"';
fanpagestring += ' data-header="' +  (lb_l_ret.facebookheader==1) + '"';
if (lb_l_ret.mab.length>0){lb_l_ret.mab += '<br>'}
fbl_otp='<a id="inline" href="#data" style="display: none;overflow:hidden;">Show</a><div style="display:none"><div id="data" style="overflow:hidden;padding:0;' + lb_l_ret.extracss + '">';
fbl_otp += lb_l_ret.mab +'<div style="overflow:hidden;width:' + lb_l_ret.width + 'px;height:' + lb_l_ret.height +'px;" class="fb-like-box" ' + fanpagestring + ' data-width="' + lb_l_ret.width +'" data-height="' + lb_l_ret.height + '" data-colorscheme="' + lb_l_ret.fbcolorscheme + '" data-show-faces="true" data-stream="false"></div>';

if ( typeof(lb_l_ret.connect)!='undefined' && lb_l_ret.connect==1 ) {
fbl_otp +='<div style="padding-bottom:3px;padding-right:3px;float:right;"><a href="#" onclick="fbloginner();" style="text-decoration:none;">' + lb_l_ret.cmessage + '</a><br /></div><div style="clear:bothl">';
}
fbl_otp +='</div></div>';
return fbl_otp;
}


function fbloginner(){
	FB.login(function(response) {
            if (response.authResponse) {

     	FB.getLoginStatus(function(response) {
	  	if (response.status === 'connected' ) {
   		var uid = response.authResponse.userID;
    	var accessToken = response.authResponse.accessToken;
    	FB.api('/'+ uid +'/likes/' + lb_l_ret.fb_id,function(response) {
	   	 if( response.data ) {
	        if( !arv__isEmpty(response.data) ) {
         //   alert('You are a fan!');
         	createCookie("arevico_lb_ns", "1", 90000);
               $j.fancybox.close();
        
    	    }
    	   }
   	    });
    }});

            }else{
               
            }
        }/*,{scope:'publish_stream'}*/
)};

	function arv__isEmpty(obj) {
    for(var prop in obj) {
        if(obj.hasOwnProperty(prop))
            return false;
    }
 
    return true;
}