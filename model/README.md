# Motion diffusion Model
Original: <https://github.com/GuyTevet/motion-diffusion-model>

### Windows Settings
Setup Conda environment for Windows:
```
conda env create -f environment.yml
conda activate mdm
python -m spacy download en_core_web_sm
pip install git+https://github.com/openai/CLIP.git
```

**HumanML3D** - Clone HumanML3D, then copy the data dir to our repository:

```shell
cd ..
git clone https://github.com/EricGuo5513/HumanML3D.git
unzip ./HumanML3D/HumanML3D/texts.zip -d ./HumanML3D/HumanML3D/
cp -r HumanML3D/HumanML3D model/dataset/HumanML3D
cd model
```

### Download the pretrained models

Download the model(s) you wish to use, then unzip and place them in `./save/`. 
<details>
  <summary><b>Text to Motion</b></summary>
[humanml-encoder-512](https://drive.google.com/file/d/1PE0PK8e5a5j-7-Xhs5YET5U5pGh0c821/view?usp=sharing)
</details>

### Download Dependencies:
<details><summary>DOWNLOAD</summary>
<p>

Download Link: <https://drive.google.com/file/d/1R0KWIQkGus1YaL7VfsZbYhn45smKPyaJ/view?usp=sharing>
  
Unzip this as "body_models". It concludes kit, smpl, t2m folders for "Text to Motion"

</p>
</details>

### RUN server
```
python -m server.server --input_path /path/to/mp4/stick/figure/file
```

model/visualize/joints2smpl/smpl_models/gmm_08.pk -> CRLF to LF

### Install Python FBX SDK
1. Download Link: <https://www.autodesk.com/developer-network/platform-technologies/fbx-sdk-2020-0> </br> Download FBX Python SDK Windows and Install
2. Link: <https://download.autodesk.com/us/fbx/20112/fbx_sdk_help/index.html?url=WS1a9193826455f5ff453265c9125faa23bbb5fe8.htm,topicNumber=d0e8312> </br>copy the contents of FBXSDK to anaconda virtual env(mdm) libs directory