'''
    Author:     NODEWAY (2016)
    
    Email:      nodeway@hotmail.com
    Twitter:    twitter.com/nodeway
    
    ----------------------------------
    IMPORTANT:
    - requires line below to be placed inside of python module: 
    author = toolutils.createModuleFromSection('author', kwargs['type'], 'AUTHOR.py') 
    
    - requires line below to be put OnCreated:
    this = kwargs['node']
    this.hdaModule().author.Populate(kwargs, 'json')   

    - example files:
    'author.xml'
    'author.json'
'''

# ---------------------------------------------------------------------
# IMPORT
# ---------------------------------------------------------------------
import hou
from hutil import json
from collections import OrderedDict
import xml.etree.ElementTree as xmltree

# ---------------------------------------------------------------------
# HELPERS
# ---------------------------------------------------------------------
def __read_file_contents__(kwargs, filename):
    '''
    '''
    asset_def = kwargs['node'].type().definition() 
    contents = asset_def.sections()[filename].contents()
    
    return contents
    
def ReadJSONData(kwargs, filename):
    '''
    '''
    contents = __read_file_contents__(kwargs, filename)     
    return json.loads(contents, object_pairs_hook=OrderedDict)
    
def ReadXMLData(kwargs, filename):
    '''
    '''
    contents = __read_file_contents__(kwargs, filename)
    return xmltree.fromstring(contents)        

def PopulateFromJSON(kwargs, folder, filename):
    '''
        Fill folder with labels that will get its data from JSON file.    
    '''
    data = ReadJSONData(kwargs, 'author.json')   

    for d in data:
        partial = '' if d.lower() == 'separator' else '{0}:'.format(d)
        formatted = '{0} {1}'.format(partial, data[d])
        
        label = hou.LabelParmTemplate(d.lower(), '', (formatted, ))
        label.hideLabel(1)
        folder.addParmTemplate(label)
        
def PopulateFromXML(kwargs, folder, filename):
    '''
        Fill folder with labels that will get its data from XML file.
    '''
    data = ReadXMLData(kwargs, 'author.xml')
    
    for d in data:
        partial = '' if d.tag.lower() == 'separator' else '{0}:'.format(d.tag)
        formatted = '{0} {1}'.format(partial, d.text)
        
        label = hou.LabelParmTemplate(d.tag.lower(), '', (formatted, ))
        label.hideLabel(1)
        folder.addParmTemplate(label)       
        
# ---------------------------------------------------------------------
# MAIN
# ---------------------------------------------------------------------    
def Populate(kwargs, type = 'json'):
    '''
        type = 'xml', 'json'
    '''
    node = kwargs['node']
    targetFolder = 'authorinfo'
    
    # check for Author section
    parms = node.parmTemplateGroup()
         
    folder = parms.find(targetFolder)
    if folder != None:       
        parms.remove(targetFolder)     
                                     
    # create and populate folder
    folder = hou.FolderParmTemplate(targetFolder, 
                                    'Author', 
                                    (), 
                                    hou.folderType.Simple, 
                                    False)  
        
    if type == 'xml':
        PopulateFromXML(kwargs, folder, 'author.xml')
    elif type == 'json':
        PopulateFromJSON(kwargs, folder, 'author.json')
          
    parms.append(folder) 
    
    # add folder
    node.setParmTemplateGroup(parms)