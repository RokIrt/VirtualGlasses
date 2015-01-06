import QtQuick 2.0
import Qt3D 2.0
import Qt3D.Shapes 2.0



Viewport {
    width: 800; height: 600
    objectName: "rootItem"
    id: rootItem
    Text{
         id:text1
        color:"red"
         text: VirtualGlasses.getCurrentDateTime();


    }


    Quad
    {
        id:stena
        position:Qt.vector3d(0, 0, 0)
        pretransform:[ Rotation3D { axis: Qt.vector3d(1, 0, 0); angle: 90 },
                        Scale3D { scale: Qt.vector3d(4, 3, 0) }
        ]
        effect: Effect
        {
            id:efekt
            color: "black"
            decal: true
         }


    }


    Item3D {
       objectName: "glasses"
       id: glasses
       visible: true
       pretransform:  Scale3D { scale: 0.0025 }

       mesh: Mesh { meshName: "mesh"; source: "../../../../source/RayBan.3ds" }
       transform: [
              Scale3D{
                id:scaleGlasses
                scale:Qt.vector3d(1,1,1)
              //  origin:qt.vector3d(0,0,0)
              },

              Rotation3D {
                  id: xRot
                  angle: 0
                  axis: Qt.vector3d(1, 0, 0)
                  origin:Qt.vector3d(0, 0,0.7)

              },
              Rotation3D {
                  id: yRot
                  angle: 0
                  axis: Qt.vector3d(0, 1, 0)
                  origin:Qt.vector3d(0, 0,0.7)
              },
              Rotation3D {
                  id: zRot
                  angle: 0
                  axis: Qt.vector3d(0, 0, 1)
                  origin:Qt.vector3d(0, 0,0.7)
              }
          ]
    }

   Timer
    {
        interval: 20; running: true; repeat: true;
//        onTriggered:{ efekt.textureImage=applicationData.getImage(); glasses.position=applicationData.getTranslation(glasses.scale); yRot.angle=applicationData.getYAngle(); xRot.angle=applicationData.getZAngle();zRot.angle=applicationData.getXAngle(); }
           onTriggered:
           {
               efekt.textureImage=VirtualGlasses.getImage();
               glasses.position=VirtualGlasses.getTranslation(glasses.scale);
               //scaleGlasses.scale=applicationData.getScale();
               scaleGlasses.scale=VirtualGlasses.getScale3d();
               scaleGlasses.origin=Qt.vector3d(0,0.25,0)

               xRot.angle=VirtualGlasses.getZAngle();
               xRot.origin=VirtualGlasses.getZOrigin(scaleGlasses.scale);
               yRot.angle=VirtualGlasses.getYAngle();
               yRot.origin=VirtualGlasses.getYOrigin(scaleGlasses.scale);
               zRot.angle=VirtualGlasses.getXAngle();
               zRot.origin=VirtualGlasses.getXOrigin(scaleGlasses.scale);

             //console.log("a is ", glasses.Center);

           }
    }



    }

