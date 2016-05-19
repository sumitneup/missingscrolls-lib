Hi.

SideFX site is not loading, but maybe you will get here so I wanted to give you a glimpse of what I put here.

It's not all yet. I will upload the rest latter.
Only two nodes are uploaded for now, VHACDDEbug and VHACDScout nodes + NODEWAY.dll which contains VHACDEngine node which is hidden, because it shouldn't be used directly, but thru VHACDGenerate which I'm reworking right now :)
But you can still use VHACDEngine without VHACDGenerate logic to test it. Just do:
node.createNode('nodeway::vhacdengine::1.0')
and it will create it.

The button called 'Show Detailed Report' on VHACDEngine doesn't work yet. I'm working on it right now. 
VHACDEngine error checks couple things, to avoid crashes:
- it triangulates geometry for you
- it makes sure that there is at least one primitive before it starts
- it makes sure that there are at leats 4 points before it starts
It also doesn't do couple things:
- it doesn't check for zero area polygons. VHACDGenerate is doing it with a help of measureSOP set to AREA. The algorithm cannot handle those type of polygons, so make sure to test it before you send it to VHACDEngine, otherwise it will crash Houdini. 

Once I upload VHACDGenerate you can forget about VHACDEngine. It should be up and running again this week, but since you wanted to test it, you can play with bare bone version too. 
You can use VHACDScout to generate some attributes and VHACDDebug to visualize them.

Before you start bumping Resolution and lowering Concativity, set Beta to low value (maybe even to zero) and Alpha to maximum. It will give you hull that follows tighter to the original geometry.

If you want to talk, there is a Slack called ProceduralDojo where we talk, mostly about Houdini (http://join-proceduraldojo.herokuapp.com/). Or send me email.

I will open nodes once I finish everything.

Have fun!