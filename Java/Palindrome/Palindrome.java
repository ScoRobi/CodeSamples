import java.io.File;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

public class Palindrome {
	
	public static String default_output_file_name = "./output.xml";
	
	public static void main(String[] args)
	{
		try
		{	
			// Ensure user input output file location
			String outputName;
			if (args.length > 0)
			{
				outputName = args[0];
			}
			else
			{
				System.out.println("Warning: No output file location provided. Defaulting to "+default_output_file_name);
				outputName = default_output_file_name;
			}
			
			// Open the input file
			File inFile = new File("Test.xml");
			DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder docBuilder = docFactory.newDocumentBuilder();
			Document input = docBuilder.parse(inFile);
			
			// Create the output file
			Document output = docBuilder.newDocument();
			Element root = output.createElement("answers");
			output.appendChild(root);
			
			// Normalize for easier parsing
			input.getDocumentElement().normalize();

			// Get a list of each 'dataset'
			NodeList nodeList = input.getElementsByTagName("dataset");
			System.out.println("Found ["+nodeList.getLength()+"] dataset/s of possible palindromes in the input file");
			
			// Parse each 'dataset'
			for (int i=0; i < nodeList.getLength(); i++)
			{
				// Get the current node (or 'dataset')
				Node curNode = nodeList.item(i);
				
				// Parse the data in the node
				if (curNode.getNodeType() == Node.ELEMENT_NODE)
				{
					// Parse the children in the node
					NodeList childNodeList = curNode.getChildNodes();
					for (int k=0; k < childNodeList.getLength(); k++)
					{
						// Only concerned with string nodes which are 'data'
						if (childNodeList.item(k).getNodeType() == 1 && 
							childNodeList.item(k).getNodeName().substring(0, 4).contains("data") )
						{						
							// Extract the useful information
							String elementStrVal = childNodeList.item(k).getTextContent();
							String nNumber = childNodeList.item(k).getNodeName();
							nNumber = nNumber.replaceAll("[a-zA-Z]", "");
							
							// Create the new element
							String curAnsName = "answer" + nNumber;
							String result;
							Element resultElement = output.createElement(curAnsName);
							
							// Check if palindrome
							boolean isPalindrome = checkPalindrome(elementStrVal, 0, elementStrVal.length()-1);
							if (isPalindrome)
							{
								System.out.println("Great Success! \'" +elementStrVal+ "\' is a palindrome!");
								result = "true";
							}
							else
							{
								System.out.println("Oh No! \'" +elementStrVal+ "\' is not a palindrome!");
								result = "false";
							}
							resultElement.appendChild(output.createTextNode(result));
							
							// Add the element to the output XML document
							root.appendChild(resultElement);
						}
					}
				}
				
			}
			
			// Print out into an XML file
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			transformer.setOutputProperty(OutputKeys.INDENT, "yes");
			DOMSource source = new DOMSource(output);
			StreamResult result = new StreamResult(new File(outputName));
			transformer.transform(source, result);
			
			System.out.println("Complete. Output file written: " + outputName);
		}
		catch (Exception e)
		{
			System.out.println("Exception caught: " +e.toString());
		}
	}
	
	public static boolean checkPalindrome(String str, int left, int right)
	{
		// Exit case - if the pointers are at the same character or pass
		if (left >= right)
		{
			return true;
		}
		
		// A=65, Z=90 ... a=97, z=122
		
		// Get the left pointer on the next character [a-z][A-Z]
		int length = str.length();
		while ( left < length && 
				(str.charAt(left) < 65 || str.charAt(left) > 90) &&
				(str.charAt(left) < 97 || str.charAt(left) > 122) )
		{
			left++;
		}
		
		// Get the right pointer on the next character [a-z][A-Z]
		while ( right >= 0 && 
				(str.charAt(right) < 65 || str.charAt(right) > 90) &&
				(str.charAt(right) < 97 || str.charAt(right) > 122) ) 
		{
			right--;
		}
		
		// Compare the two characters -- call recursively if chars match, return false if not
		if ( Character.toLowerCase(str.charAt(left)) == Character.toLowerCase(str.charAt(right)) )
		{
			left++;
			right--;
			return checkPalindrome(str, left, right);
		}
		else
		{
			return false;
		}
	}
	
}
