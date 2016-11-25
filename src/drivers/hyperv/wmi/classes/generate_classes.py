import json

with open('classes.json') as json_data:
    d = json.load(json_data)
    print(d['namespaces'])
    
    for namespace in d['namespaces']:
        print(namespace['name'])
        namespace['name'] = 'test'

    with open('classes.json', 'w') as outfile:
        json.dump(d, outfile, indent=4, separators=(',', ':'))