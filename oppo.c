-------------============================================camera screen customization==============================================-----------------------------------


-handle resolution


final controller = VideoPlayerController.network(videoUrl)
  ..initialize().then((_) {
    setState(() {
      controller.play();
    });
  })
  ..setLooping(true)
  ..setVolume(1.0)
  ..setPlaybackSpeed(1.0)
  ..setIsBuffering(false)
  ..setMixWithOthers(true)
  ..setAutoRepeatMode(true)
  ..setUseHardwareDecoder(true); // Enable hardware acceleration








-handle peinch zoom

double _scale = 1.0;

GestureDetector(
  onScaleUpdate: (ScaleUpdateDetails details) {
    setState(() {
      _scale = details.scale>5.0?5.0:details.scale<1.0?1.0:1.0;
    });
  },
  child: Transform.scale(
    scale: _scale,
    child: SizedBox(
      height: /* video player height */ * _scale,
      width: /* video player width */ * _scale,
      child: VideoPlayer(/* video player widget */),
    ),
  ),
)












===================================================================================================================================




-control back button in smartphone


return WillPopScope(
  onWillPop: () async {
    // Handle back button press event
    // Navigate back to the desired screen
    return true;
  },
  child: Scaffold(
    appBar: AppBar(title: Text('My Screen')),
    body: Center(
      child: Text('Hello, world!'),
    ),
  ),
);
```



























navigation tool to bach soeecific screen ....first with name route ....second with constructor name



onWillPop: () async {
  // Navigate back to the desired screen
  Navigator.of(context).popUntil(ModalRoute.withName('/desired-screen'));
  return true;
}







Navigator.of(context).popUntil((route) => route.settings.name == 'DesiredScreen');


























================================================================================================================

Class PageTransition extends PageRouteBuilder{

final page;

PageTransition ({this.page}):super(pageBuilde:(context,animation,animationtwo)=>page,transitionBuilder:(context,animation,animationtwo,child){

return Align(alignment:Alignment.topLeft,child:SizedTransition(sizedFactor:animation,child:child));

});













}

